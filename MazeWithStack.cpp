#include<bits/stdc++.h>

using namespace std;

int main()
{
  int column,row,i,j;
  cout<<"Coloumn,Row:";cin>>column>>row;

  int **maze=new int*[row+1];
  for(int i=0;i<row+1;i++)
  maze[i]=new int[column+1];

  for(i=0;i<row;i++)
  {
  maze[i][0]=1;
  maze[i][column-1]=1;
  }
  for(i=0;i<column;i++)
  {
  maze[0][i]=1;
  maze[row-1][i]=1;
  }

  for(i=1;i<row;i++)
  for(j=1;j<column;j++)
  cin>>maze[i][j];

  cout<<"\nMaze:\n";

  for(i=1;i<row-1;i++)
  {
  for(j=1;j<column-1;j++)
  cout<<maze[i][j]<<" ";
  cout<<"\n";
  }





  return 0;
}
