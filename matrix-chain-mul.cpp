#include<bits/stdc++.h>

using namespace std;
int m[1000][1000],s[1000-1][1000];
void print(int i,int j)
{
  if(i==j)
  cout<<i<<",";
  else{
  cout<<"(";print(i,s[i][j]);print(s[i][j]+1,j);cout<<")";}
}
int main()
{
  int n;
  cin>>n;
  int p[n+1];
  for(int i=0;i<n+1;i++)
    cin>>p[i];
  memset(m,0,sizeof(m));

  for(int i=0;i<n+1;i++)
  {
  for(int j=0;j<n+1;j++)
  cout<<m[i][j]<<" ";
  cout<<endl;
  }
  for(int l=2;l<=n;l++)
  {
    for(int i=1;i<=n-l+1;i++)
    {
      int j=i+l-1;
      m[i][j]=100000;
      for(int k=i;k<j;k++)
      {
        int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
        if(q<m[i][j])
          m[i][j]=q,s[i][j]=k;
      }
    }
  }
  for(int i=0;i<n+1;i++)
  {
  for(int j=0;j<n+1;j++)
  cout<<m[i][j]<<" ";
  cout<<endl;
  }
  print(1,n);
}
