#include<bits/stdc++.h>
using namespace std;
int main()
{
int t=20;
ofstream f;
ofstream fz;
fz.open("input_city_dptsp.txt");
f.open("input_city.txt");
srand(time(0));
f<<t;
f<<"\n";
fz<<t;
fz<<"\n";
  while(t--)
  {
    int r=rand()%12+1;
    f<<r;
    f<<"\n";
    fz<<r;
    fz<<"\n";
    int z=r;
    for(int i=0;i<z;i++)
    {
      for(int j=0;j<z;j++)
      {
        if(i!=j)
        r=rand()%50+1;
        else
        r=0;
        f<<r;
        f<<" ";
        fz<<r;
        fz<<" ";
      }
      f<<"\n";
      fz<<"\n";
    }
    r=rand()%5+1;
    f<<"2";
    f<<"\n";
    r=rand()%5+1;
    f<<"1";
    f<<"\n";
    f<<"300";
    f<<"\n";
    r=rand()%150+50;
    f<<"200";
    f<<"\n";
  }
}
