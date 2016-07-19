#include<bits/stdc++.h>
using namespace std;

int exp(int n,int k)
{
  int s,t;
  if(k==2)
  return n*n;
  if(k==1)
  return n;

  if(k%2==0&&k>2)
  {
    s=exp(n,k/2);
    return s*s;
  }
  else if(k%2==1&&k>2)
  {
    s=exp(n,k/2);
    return s*s*n;
  }
}

int main()
{
  int n,k;
  while(1){
  cout<<"\nnumber,exp:";
  cin>>n;cin>>k;
  cout<<"\nAnswer:"<<exp(n,k);
}  return 0;
}
