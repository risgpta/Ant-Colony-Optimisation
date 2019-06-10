#include<bits/stdc++.h>
using namespace std;
int tsp(int dp[][1<<12],int mask,int i,int a[][12],int n)
{
  if(mask==((1<<n)-1))
  return a[i][0];
  if(dp[i][mask]==-1)
  {
    int z=999999;
    for(int j=0;j<n;j++)
    {
      if((mask&(1<<j))==0)
      z=min(z,a[i][j]+tsp(dp,mask|(1<<j),j,a,n));
    }
    dp[i][mask]=z;
  }
  return dp[i][mask];
}
int main()
{
  int t;
  cin>>t;
  ofstream f;
  f.open("output-tsp.txt");
  int c=0;
  while(t--)
  {
    c++;
    int n;
    cin>>n;
    int a[n][12];
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      cin>>a[i][j];
    }
    int dp[n+1][(1<<12)];
    memset(dp,-1,sizeof(dp));
    int z=tsp(dp,1,0,a,n);
    f<<c;
    f<<" ";
    f<<z;
    f<<"\n";
  }
}
