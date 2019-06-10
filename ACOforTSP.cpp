#include<bits/stdc++.h>
using namespace std;
int it;
class ant
{
public:
  bool city_list[20];
  int index;
  int start_city;
  int next_city;
  vector <int> v;
};
class city
{
public:
  int num_of_cities;
  int distance[20][20];
  float phermone_level[20][20];
  int alpha;
  int beta;
  ant obj[205];
  void initialise();
  void start_aco(int n,int &zt);
  inline void place_them(int a,int b,int cc);
  void go(int k);
  int here(int k);
  void evaporate();
  void ant_initialise(int n);
  void input();
};
void city :: initialise()
{
  //cout<<"Initial phermone = 1.0 for all paths \n\n";
  for(int i=0;i<num_of_cities;i++)
  {
    for(int j=0;j<num_of_cities;j++)
      phermone_level[i][j]=1.0;
  }
}
void city :: input()
{
  for(int i=0;i<num_of_cities;i++)
  {
    for(int j=0;j<num_of_cities;j++)
    cin>>distance[i][j];
  }
}
int city :: here(int k)
{
  int cc=obj[k].next_city;
  map <int,int> mp;
  int len=0;
  float sum_phermone=0;
  for(int i=0;i<num_of_cities;i++)
  {
    if(obj[k].city_list[i]==false && )
    {
      mp[len]=i;
      len++;
    }
  }
  float prefix_sum[len];
  float prob[len];
  for(int i=0;i<len;i++)
  {
  float x=pow(1.0*phermone_level[cc][mp[i]],alpha);
  float y=pow(1.0/distance[cc][mp[i]],beta);
  prob[i]=x*y;
  sum_phermone+=prob[i];
  }
  for(int i=0;i<len;i++)
  prob[i]/=sum_phermone;
    prefix_sum[0]=prob[0];
  for(int i=1;i<len;i++)
  prefix_sum[i]=prefix_sum[i-1]+prob[i];
  float r= float(rand()) / ( float(RAND_MAX) + 1.0);
  r*=prefix_sum[len-1];
  int z=upper_bound(prefix_sum,prefix_sum+len,r)-prefix_sum;
  return mp[z];
}
void city :: go(int k)
{
  if(obj[k].v.size()==0)
  {
  for(int l=0;l<num_of_cities;l++)
  obj[k].city_list[l]=false;
  obj[k].city_list[obj[k].start_city]=true;
  obj[k].next_city=obj[k].start_city;
  }
  if(obj[k].v.size()==(num_of_cities-1))
  {
    obj[k].v.push_back(obj[k].start_city);
    phermone_level[obj[k].next_city][obj[k].start_city]+=0.5;
    return;
  }
  int where_it_should_go=here(k);
//  cout<<where_it_should_go<<" \n";
  obj[k].city_list[where_it_should_go]=true;
  obj[k].v.push_back(where_it_should_go);
  phermone_level[obj[k].next_city][where_it_should_go]+=0.5;
  obj[k].next_city=where_it_should_go;
  for(int l=0;l<num_of_cities;l++)
  cout<<obj[k].city_list[l]<<" ";
  cout<<"\n";
  go(k);
}
inline void city :: place_them(int a,int b,int cc)
{
  for(int i=a;i<=b;i++)
  obj[i].start_city=cc;
}
void city :: evaporate()
{
  //cout<<"Evaporating phermone...\n\n";
  for(int i=0;i<num_of_cities;i++)
  {
    for(int j=0;j<num_of_cities;j++)
      phermone_level[i][j]-=0.3;
  }
}
void city :: ant_initialise(int n)
{
  for(int i=0;i<n;i++)
  obj[i].v.clear();
  int z=n/num_of_cities;
  int k=0;
  /*for(int i=0;i<n;i+=z)
  place_them(i,i+z-1,k++);
  int zz=n%num_of_cities;
  place_them(z*num_of_cities,z*num_of_cities+zz-1,0);*/
  for(int i=0;i<n;i++)
  obj[i].start_city=0;
}
void city :: start_aco(int n,int &zt)
{
    evaporate();
    //cout<<it--<<":-\n";
    ant_initialise(n);
    for(int i=0;i<n;i++)
    go(i);
    for(int i=0;i<n;i++)
    {
      int sum=0;
      for(int j=0;j<obj[i].v.size();j++)
      {
      if(j==0)
      sum+=distance[obj[i].start_city][obj[i].v[j]];
      else
      sum+=distance[obj[i].v[j-1]][obj[i].v[j]];
      cout<<obj[i].v[j]<<" ";
      }
      cout<<"\nCOST:\n";
      cout<<sum;
      zt=min(zt,sum);
      cout<<"\n";
    }
    cout<<"\n\n";
}
int main()
{
  srand (static_cast <unsigned> (time(0)));
  int t;
  cin>>t;
  ofstream f;
  f.open("output-aco-tsp.txt");
  int ccc=0;
  while(t--)
  {
    ccc++;
  int n;
  cin>>n;
  city c;
  c.num_of_cities=n;
  c.input();
  int p,q;
  cin>>p;
  cin>>q;
  c.alpha=p;
  c.beta=q;
  int num_of_iterations;
  cin>>num_of_iterations;
  int num_of_ants;
  cin>>num_of_ants;
  it=num_of_iterations;
  int zt=999999;
  c.initialise();
  while(num_of_iterations--)
  {
  c.start_aco(num_of_ants,zt);
  }
  cout<<zt<<"\n";
  f<<ccc;
  f<<" ";
  f<<zt;
  f<<"\n";
  }
}
