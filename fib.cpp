#include<bits/stdc++.h>
using namespace std;
//tes
int s[2][2]={{1,1},{1,0}};
int f[2][2]={{1,1},{1,0}};
int res[2][2]={{1,0},{0,1}};
void matrixMultiply(int a[2][2],int b[2][2])
{
  int c[2][2]={{0,0},{0,0}};
  for(int i=0;i<2;i++)
  for(int j=0;j<2;j++)
  {
    c[i][j];
    for(int k=0;k<2;k++)
    c[i][j]=c[i][j]+a[i][k]*b[k][j];
  }
  s[0][0]=c[0][0];
  s[0][1]=c[0][1];
  s[1][0]=c[1][0];
  s[1][1]=c[1][1];

}
void matrixEvenMultiply(int a[2][2],int b[2][2])
{
  int c[2][2]={{0,0},{0,0}};
  for(int i=0;i<2;i++)
  for(int j=0;j<2;j++)
  {
    c[i][j];
    for(int k=0;k<2;k++)
    c[i][j]=c[i][j]+a[i][k]*b[k][j];
  }
  res[0][0]=c[0][0];
  res[0][1]=c[0][1];
  res[1][0]=c[1][0];
  res[1][1]=c[1][1];

}

int exp(int s[2][2],int k)
{
  while(k>0)
  {

  if(k&1)
  matrixEvenMultiply(res,s);
  k=k/2;
  matrixMultiply(s,s);
}
  return res[0][0];
}

int main()
{
  int n,k;
  while(1){
  cout<<"\n\nnth fib of:";
  cin>>k;
  cout<<"Answer:"<<exp(s,k-1);
  s[0][0]=1;
  s[0][1]=1;
  s[1][0]=1;
  s[1][1]=0;
  res[0][0]=1;
  res[0][1]=0;
  res[1][0]=0;
  res[1][1]=1;
}  return 0;
}
