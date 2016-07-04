#include<bits/stdc++.h>

using namespace std;

struct node
{
  int data;
  bool colour;
  node* parent;
  node* right;
  node* left;
};

node* create(int d)
{
  node* newNode=new node;
  newNode->data=d;
  newNode->colour=false;
  newNode->parent=NULL;
  newNode->right=NULL;
  newNode->left=NULL;
  return newNode;
}

node* insertBtree(node* &n,node* &d,int c=1)
{
  if(n==NULL&&c==1)
  {
    d->colour=true;
    return d;
  }
  else
    if(n==NULL&&c==0){
      d->colour=false;
      return d;
    }

    if(d->data<=n->data)
        {
          n->left=insertBtree(n->left,d);
          n->left->parent=n;
        }
      else
        {
          n->right=insertBtree(n->right,d);
          n->right->parent=n;
        }
        return n;//you need to return the appropriate nodes
                //thus updating all the node value after insertion
}

void printBtree(node* temp) {
  if(temp!=NULL)
  {
    printBtree(temp->left);
    cout<<" "<<temp->data;//<<":"<<temp->parent<<":";
    printBtree(temp->right);
  }
  return;
}

int main()
{
  node *root=NULL;
  int choice=1;
  int data;

  cout<<"\nenter data:";
  cin>>data;
  node *newroot=create(data);
  root=insertBtree(root,newroot,0);/*root need to change its value from null hence root
                                    is assigned the value of return*/

  while(choice!=0)
  {
    cout<<"\nenter choice(1.Insert 2.print):";
    cin>>choice;
    node *newNode=create(0);
    switch (choice) {
      case 1: int data;
              cout<<"\nenter data:";
              cin>>data;
              newNode->data=data;
              insertBtree(root,newNode);
              break;
      case 2:printBtree(root);
              break;
    }
  }
  return 0;
}
