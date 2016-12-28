#include<bits/stdc++.h>

using namespace std;
struct node
{
  int i,j;
  node *next;
};
void push(node *&s,int i,int j)
{
  node*temp;
  node*newNode=new node;
  newNode->i=i;
  newNode->j=j;
  if(s==NULL)
  {
    s=newNode;
  }
  else
  {
    temp=s;
    s=newNode;
    newNode->next=temp;
  }
}
node* pop(node*&s)
{
  node*rtrn=new node;
  node*temp;
  if(s==NULL)
  return NULL;
  else
  {
    temp=s;
    s=s->next;
    rtrn=temp;
    rtrn->i=temp->i;
    rtrn->j=temp->j;
    rtrn->next=NULL;

    return rtrn;
  }
}
void draw(int **maze,int row,int column)
{
  cout<<"\nMaze:\n";

  for(int i=0;i<row;i++)
  {
  for(int j=0;j<column;j++)
  if(maze[i][j]<0)
  {cout<<maze[i][j]<<" ";}
  else
  {cout<<maze[i][j]<<"  ";}
  cout<<"\n";
  }

}
void cord(int **maze,int row,int column)
{
  cout<<"\nMaze:\n";

  for(int i=0;i<row;i++)
  {
  for(int j=0;j<column;j++)
  if(maze[i][j]==0)
  {cout<<endl<<i<<","<<j;}

  }

}
void printStack(node*s)
{
  cout<<"\n";
  while(s!=NULL)
  {
    cout<<"->"<<s->i<<","<<s->j;
    s=s->next;
  }
}
int main()
{
  //walls are represented as 1's and paths are represented by 0's
  int column,row,i,j;
  node *s=new node;
  s=NULL;


  cout<<"Coloumn,Row:";cin>>column>>row;
  row+=2;//column numbers are increased by 2 for convinience
  column+=2;//Hence boundry conditions of maze need not be hard coded
  //they can be represented as walls
  int **maze=new int*[row];

  for(int i=0;i<row+2;i++)
    maze[i]=new int[column];

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

for(int i=1;i<row-1;i++)
  for(int j=1;j<column-1;j++)
    {
      cin>>maze[i][j];
    }



  cout<<"\nMaze:\n";

  for(i=0;i<row;i++)
  {
  for(j=0;j<column;j++)
  cout<<maze[i][j]<<" ";
  cout<<"\n";
  }
  //draw(maze,row,column);
  //cord(maze,row,column);

  int starti,startj,endi,endj;
  cout<<"\nINDEXING IS FROM ONE!\n";
  cout<<"\nStart i,j:";cin>>starti>>startj;
  cout<<"\nEnd i,j:";cin>>endi>>endj;
  push(s,starti,startj);
  node*temp;
  while(temp!=NULL)
  {
    //if path is clear move to that square
    //before pushing mark the current tile as -1
    //to avoid infinite loop
    if(maze[starti+1][startj]==0)
    {
      maze[starti][startj]=-1;push(s,starti,startj);
      starti+=1;
    }
    else
    if(maze[starti-1][startj]==0)
    {
      maze[starti][startj]=-1;push(s,starti,startj);
      starti-=1;
    }
    else
    if(maze[starti][startj+1]==0)
    {
      maze[starti][startj]=-1;push(s,starti,startj);
      startj+=1;
    }
    else
    if(maze[starti][startj-1]==0)
    {
      maze[starti][startj]=-1;push(s,starti,startj);
      startj-=1;
    }
    else
    if(starti==endi&&startj==endj)
    {
      printStack(s);
      break;
    }
    else//if stuck make the current tile 1.traceback and make a different choice now.
    {
      maze[starti][startj]=1;
      temp=pop(s);
      if(temp!=NULL)
      {
        starti=temp->i;
        startj=temp->j;
        if(maze[starti][startj]==-1)
          maze[starti][startj]=0;
        }
        else
        {
          cout<<"\nMouse Is trapped forever :(";
          break;
        }
    }
      
  }

  return 0;
}
//sample maze coloumn:24 row:12
//0 1 1 1 0 1 0 1 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 0 1 0 0 0 0 0 1 1 1 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 1 0 1 1 1 1 1 0 1 1 0 1 1 1 0 1 1 1 0 0 0 1 0 0 1 0 1 0 0 0 1 0 1 0 0 1 0 1 0 1 0 1 0 0 0 1 0 0 1 0 1 1 1 0 1 1 1 0 1 1 0 0 0 1 0 1 0 0 1 1 1 0 1 0 0 0 1 0 0 0 1 0 1 1 1 1 0 0 0 1 0 0 0 0 0 0 0 0 1 0 1 0 1 0 0 0 1 0 0 0 0 1 1 1 0 1 1 1 0 0 1 1 1 0 0 0 1 1 1 0 0 0 1 1 0 0 0 0 0 1 0 1 1 0 0 0 1 1 1 1 1 0 1 0 1 0 1 1 0 1 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 1 0 1 0 1 1 0 0 1 1 0 1 1 1 1 1 1 0 1 1 1 1 1 0 1 0 1 0 1 1 1 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 1 1 1
