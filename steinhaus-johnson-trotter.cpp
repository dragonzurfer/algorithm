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
        if(abs(oldmax)>abs(a[i]))//avoiding the previous max element
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
    max=findmax(a,n,currentMax);//firs time a huge value is passed
                                //if the previous largest element was not mobile
                                //we need to find the next largest.
                                //hence we pass the oldmax whixh the variable currentMax

    currentMax=a[max];//tracks the currentMax
    if(a[max]<0&&max!=0)//<0 means pointing towards left,
    {                   //also checking if the element is not in the beginning
      if(abs(a[max-1])<abs(a[max]))
       {
        return max-1;
       }
    }
    else
    if(a[max]>0&&max!=n-1)//>0 means pointing towards right
    {                      //also checking if the element is not at the end
      if(abs(a[max+1])<abs(a[max]))
      {
        return max+1;
      }
    }
  }
  return -1;//if the for loop is done.it means there was no mobile.to indicate no mobile number. return -1

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
  cout<<" "<<a[i];
}
int main()
{
  int n,pos,k;
  cout<<"Digits:";
  cin>>n;
  int *a=new int[n];
  for(int i=0;i<n;i++)
  a[i]=-(i+1);//negative represents left direction
  k=0;
  printArray(a,n);
 while(mobile(a,n)!=-1)
  {
    pos=mobile(a,n);//finds the pos of the adjacent elment to the
                    //largest mobile elment


    swap(a,maxpos,pos);//maxpos maintains the pos of largest mobile number

    update(a,n,pos);//maxpos is interchanges with pos hence updating by passing pos

    printArray(a,n);//prints the state of the array
cin>>k;
    k++;
  }
  cout<<"\nnumber of permutations:"<<k+1;
  return 0;
}
