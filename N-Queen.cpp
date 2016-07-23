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
void printStack(node*s)
{
  cout<<"\n";
  while(s!=NULL)
  {
    cout<<"->("<<s->i<<","<<s->j<<")";
    s=s->next;
  }
}
void draw(int maze[8][8],int row,int column)
{
  cout<<"\nMaze:\n";

  for(int i=0;i<row;i++)
  {
  for(int j=0;j<column;j++)
  if(maze[i][j]<0)
  {cout<<maze[i][j]<<"  ";}
  else
  {cout<<maze[i][j]<<"";}
  cout<<"\n";
  }

}
int checkboard(int board[8][8],int currenti,int currentj,int row,int column)
{
  int i=currenti,j=currentj;
  cout<<endl<<"Row";
  while(j>=0)
  {
    cout<<endl<<i<<","<<j<<":"<<board[i][j];
    if(board[i][j]==1)
    {
      return 0;
    }
    else
    j-=1;
  }
  cout<<endl<<"lower diag";
  i=currenti;j=currentj;
  while(i>=0&&j>=0)
  {
      cout<<endl<<i<<","<<j<<":"<<board[i][j];
    if(board[i][j]==1)
    {
      return 0;
    }
    else
    {j-=1;i-=1;}
  }
  cout<<endl<<"upper diag";
  i=currenti;j=currentj;
  while(i<row&&j>=0)
  {
      cout<<endl<<i<<","<<j<<":"<<board[i][j];
    if(board[i][j]==1)
    {
      return 0;
    }
    else
    {j-=1;i+=1;}
  }
  return 1;
}

int main()
{
  int board[8][8]={0},i=0,j=0;
  int num,k;
  cout<<"\nNumber of Queens:";
  cin>>num;
  int currentNum=0;
  node*s=NULL;
  node*temp;
  while(currentNum!=num)
  {

    if(i==8)
    {
      cout<<"\nPOPING:";
      temp=pop(s);
      board[temp->i][temp->j]=0;
      currentNum-=1;
      i=temp->i+1;
      j-=1;
      if(temp==NULL)
      {
        cout<<"Not possible!!";
        break;
      }
    }
    else
    if(board[i][j]==0&&checkboard(board,i,j,8,8)==1)
    {
      cout<<"\nFOUND POS";
      board[i][j]=1;
      currentNum+=1;
      push(s,i,j);
      i=0;
      j+=1;
    }
    else
    {
      cout<<"\nNEXT";
      i+=1;
    }
    printStack(s);
    draw(board,8,8);

  }


  return 0;
}
