#include<bits/stdc++.h>
using namespace std;

int s[2][2]={{1,1},{1,0}};
int f[2][2]={{1,1},{1,0}};

void matrixMultiply(int res[2][2],int a[2][2],int b[2][2])
{
  //int x =  a[0][0]*b[0][0] + a[0][1]*b[1][0];
  //int y =  a[0][0]*b[0][1] + a[0][1]*b[1][1];
  //int z =  a[1][0]*b[0][0] + a[1][1]*b[1][0];
  //int w =  a[1][0]*b[0][1] + a[1][1]*b[1][1];
  int c[2][2]={{0,0},{0,0}};
  for(int i=0;i<2;i++)
  for(int j=0;j<2;j++)
  {
    c[i][j];
    for(int k=0;k<2;k++)
    c[i][j]=c[i][j]+a[i][k]*b[k][j];
  }
  res[0][0]=c[0][0];//x;
  res[0][1]=c[0][1];//y;
  res[1][0]=c[1][0];//z;
  res[1][1]=c[1][1];//w;

}

int exp(int s[2][2],int k)
{
  int res[2][2]={{1,0},{0,1}};
  while(k>0)
  {
    if(k&1)
    matrixMultiply(res,res,s);
    k=k>>2;
    matrixMultiply(s,s,s);
  }
  return s[0][0];
}

int main()
{
  int n,k;
  while(1){
  cout<<"\nnth fib o:";
  cin>>k;
  cout<<"\nAnswer:"<<exp(s,k-1);
  s[0][0]=1;
  s[0][1]=1;
  s[1][0]=1;
  s[1][1]=0;
}  return 0;
}
