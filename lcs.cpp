#include<bits/stdc++.h>

using namespace std;
  string s1,s2;
  int n,m;
    int dp[1000][1000],dp2[1000][1000];
int print(int i,int j)
{
  //cout<<i<<","<<j<<endl;
  //int t;cin>>t;
  if(i==0||j==0)
  return 1;

  if(dp2[i][j]==0){
    print(i-1,j-1);
    cout<<s2[j-1];//<<"("<<j<<")-";
    // cout<<s1[i-1]<<"("<<i<<")";
  }
  else if(dp2[i][j]==1)
   print(i-1,j);
  else print(i,j-1);
  return 0;
}
int main()
{

  cin>>s1>>s2;
  m=s1.length(),n=s2.length();

  memset(dp,0,sizeof(dp));
  for(int i=1;i<=m+1;i++)
  {
    for(int j=1;j<=n+1;j++)
    {
      if(s1[i-1]==s2[j-1])
        dp[i][j]=(dp[i-1][j-1]+1),dp2[i][j]=0;
      else if (dp[i-1][j]>dp[i][j-1])
        dp[i][j]=dp[i-1][j],dp2[i][j]=1;
      else
        dp[i][j]=dp[i][j-1],dp2[i][j]=-1;

    }
  }

  cout<<"length:"<<dp[n][m];
  cout<<endl<<"example:";print(n,m);
  return 0;
}
