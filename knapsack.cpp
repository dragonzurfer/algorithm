#include<bits/stdc++.h>
int tot;
using namespace std;
int maxi(int a, int b) { return (a > b)? a : b; }
void draw(int **k,int value[],int w[],int n,int totalCapacity)
{
  cout<<"\nA\n  ";
  for(int i=0;i<totalCapacity+1;i++)
  cout<<i<<" ";
  cout<<endl;
  for(int l=0;l<=n;l++)
  {
    if(l!=0)
    cout<<value[l-1]<<"|";
    else
    cout<<"V|";
    for(int q=0;q<=totalCapacity;q++)
    cout<<k[l][q]<<" ";
    cout<<endl;
  }
}
void traceItems(int **k,int value[],int w[],int n,int totalCapacity)
{
  int i,j;
  cout<<"\nSolution\n";
  i=n,j=totalCapacity;
  while(i>0&&j>0)
  {
    if(k[i][j]!=k[i-1][j])
    {
      if(totalCapacity!=0)
      {totalCapacity=totalCapacity-w[i-1];
      cout<<"\nPick item:"<<i<<" of weight:"<<w[i-1];}
      i=i-1;j=j-w[i-1];
    }
    else
    i-=1;
  }
}

int knapsack(int value[],int w[],int n,int totalCapacity)
{
  int i,j;
  int **k;
  k = new int *[n+1];
  int recon[n+1][totalCapacity+1];
  for(int i = 0; i <n+1; i++)
    k[i] = new int[totalCapacity+1];

  for(int i=0;i<n+1;i++)
  for(int j=0;j<totalCapacity+1;j++)
  k[i][j]=0;

  for (i = 0; i <=n; i++)
  {
    for ( j = 0; j <=totalCapacity; j++)
    {
        if(i==0||j==0)
        k[i][j]=0;
        else if(w[i-1]<=j)
        {
        // k[i][j]=maxi(value[i-1]+k[i-1][j-w[i-1]],k[i-1][j]);
        	if(value[i-1]+k[i-1][j-w[i-1]]>=k[i-1][j])
        		{k[i][j]=value[i-1]+k[i-1][j-w[i-1]];recon[i][j]=i-1;}
        	else{ k[i][j]=k[i-1][j];recon[i][j]=-1;}
    	}
        else
        k[i][j]=k[i-1][j];
        //representation of matrix after each state
        //draw(k,value,w,n,totalCapacity);
    }
  }
   traceItems(k,value,w,n,totalCapacity);

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
  tot=totalCapacity;

  cout<<"\nMax value that can be packed is:"<<knapsack(value,w,n,totalCapacity);

  return 1;
}
