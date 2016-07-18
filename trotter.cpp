#include<bits/stdc++.h>

using namespace std;
int maxpos=0;

void swap(int a[],int i,int j)
{
  int temp;
  temp=a[i];
  a[i]=a[j];
  a[j]=temp;
}

int findmax(int a[],int n,int oldmax)
{
  int m=0;
  maxpos=-1;
  for(int i=0;i<n;i++)
  {
    if(abs(a[i])>abs(m))
      {
        if(abs(oldmax)>abs(a[i]))
        {
        maxpos=i;
        m=a[i];
        }
      }
  }
  return maxpos;
}

int mobile(int a[],int n)
{
  int currentMax=10000,max;
  for(int i=0;i<n;i++)
  {
    max=findmax(a,n,currentMax);

    currentMax=a[max];
    if(a[max]<0&&max!=0)
    {
      if(abs(a[max-1])<abs(a[max]))
       {
        return max-1;
       }
    }
    else
    if(a[max]>0&&max!=n-1)
    {
      if(abs(a[max+1])<abs(a[max]))
      {
        return max+1;
      }
    }



  }

}
void update(int a[],int n,int max)
{
  for(int i=0;i<n;i++)
    {
      if(abs(a[i])>abs(a[max]))
      a[i]=-a[i];
    }
}
void printArray(int a[],int n)
{
  cout<<"\n";
  for(int i=0;i<n;i++)
  cout<<" "<<abs(a[i]);
}
int main()
{
  int n,pos,k;
  cout<<"Digits:";
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++)
  a[i]=-(i+1);
  k=0;
  printArray(a,n);
 while(1)
  {
    pos=mobile(a,n);
    if(pos==n)
    break;

    swap(a,maxpos,pos);

    update(a,n,pos);

    printArray(a,n);
    k++;
  }
  cout<<"\nnumber of permutations:"<<k+1;
  return 0;
}
