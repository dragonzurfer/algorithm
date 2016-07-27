#include<bits/stdc++.h>

using namespace std;
int maxi(int a, int b) { return (a > b)? a : b; }
int knapsack(int value[],int w[],int n,int totalCapacity)
{
  int i,j;
  int k[n+1][totalCapacity+1];

  for (i = 0; i <=n; i++)
  {
    for ( j = 0; j <=totalCapacity; j++)
    {
        if(i==0||j==0)
        k[i][j]=0;
        else if(w[i-1]<=j)
        k[i][j]=maxi(value[i-1]+k[i-1][j-w[i-1]],k[i-1][j]);
        else
        k[i][j]=k[i-1][j];
        cout<<"\nA\n";
        for(int l=0;l<=n;l++)
        {
          for(int q=0;q<=totalCapacity;q++)
          cout<<k[l][q]<<" ";
          cout<<endl;
        }
    }
  }

  return k[n][totalCapacity];
}

int main()
{
  int n;
  cout<<"\n Number of Items:";
  cin>>n;
  int *w = new int[n];
  cout<<"\n Respective weights of items:";
  for(int i=0;i<n;i++)
  cin>>w[i];

  int *value = new int[n];
  cout<<"\n Respective value of items:";
  for(int i=0;i<n;i++)
  cin>>value[i];

  int totalCapacity;
  cout<<"Capacity of the knapsack:";
  cin>>totalCapacity;

  cout<<"\nMax value that can be packed is:"<<knapsack(value,w,n,totalCapacity);

  return 1;
}
