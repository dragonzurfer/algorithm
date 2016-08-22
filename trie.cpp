#include<bits/stdc++.h>
#define intmin 32
using namespace std;

struct node{
  int val;
  node*a[2];
};
node* newnode()
{
  node* n=new node;
  n->a[0] = n->a[1] = NULL;
  n->val=0;
  return n;

};
void insert(node*&root,int num)
{
  bool val;
  node* temp=root;
  int l;int count=0;;
  for (int i = intmin-1; i >=0; i--)
  {
    val=num&(1<<i);

    if(temp->a[val]==NULL)
    temp->a[val]=newnode();
    temp=temp->a[val];
  }
  temp->val=num;
}
int search(node*root,int num)
{
  bool val;

  for(int i=intmin-1;i>=0;i--)
  {
    val=num&(1<<i);
    if(root->a[1-val]!=NULL)
    root=root->a[1-val];
    else
      if(root->a[val]!=NULL)
      root=root->a[val];
  }
  return root->val;
}
void del(node*&root)
{
  if(root!=NULL)
  {
    del(root->a[0]);
    delete root;
    del(root->a[1]);

  }
}

void deletetree(node*temp,int num,int i)
{
  bool val,flag;
  node* tobe;
  int dir;

  for( i=intmin-1;i>=0;i--)
  {
    val=num&(1<<i);

    if(temp->a[val]!=NULL)
    {
      if(temp->a[0]!=NULL&temp->a[1]!=NULL)//finds the last shared node
      {
        dir=val;//the direction of the nodes to be deleted from the shared node
        tobe=temp;
      }
    temp=temp->a[val];
    if(temp->val==num)
    flag=true;

    }
  }

  if(flag)
  {
      temp->val=0;
      if(dir==1)
      {del(tobe->a[1]);tobe->a[1]=NULL;}
      else
      {del(tobe->a[0]);tobe->a[0]=NULL;}
    }


}
void printree(node*p)
{

  if(p!=NULL)
  {
    printree(p->a[0]);
    cout<<" "<<p->val;
    printree(p->a[1]);
  }
    return;
}

int main()
{
  int num;
  int choice=1;
  node*root=new node;
  root->val=0;
  root->a[0]=root->a[1]=NULL;
  insert(root,0);
  while(choice)
  {
    cout<<"\n 1.insert 2.delete 3.findmax \nchoice:";cin>>choice;
    switch (choice) {
      case 1:cout<<"\nnumber:";cin>>num;
           insert(root,num);
            break;
      case 2:cout<<"\nnumber:";cin>>num;deletetree(root,num,intmin);
            break;
      case 3:cout<<"\nnumber:";cin>>num;cout<<"max num:"<<search(root,num);
            break;
      case 4:printree(root);
            break;
    }
  }
}
