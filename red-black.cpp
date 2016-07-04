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

node* insertBtree(node*n,int d,int c=1)
{
  if(n==NULL&&c==1)
  {
    node* n=new node;
    n->data=d;
    n->colour=c=true;
    n->parent=NULL;
    n->right=NULL;
    n->left=NULL;
    return n;
  }
  else
    if(n==NULL&&c==0){
      node* n=new node;
      n->data=d;
      n->colour=false;
      n->parent=NULL;
      n->right=NULL;
      n->left=NULL;
      return n;
    }

    if(d<=n->data)
        {
          n->left=insertBtree(n->left,d);
          n->left->parent=n;
        }
      else
        {
          n->right=insertBtree(n->right,d);
          n->right->parent=n;
        }
        return n;
}

void printBtree(node* temp) {
  if(temp!=NULL)
  {
    printBtree(temp->left);
    cout<<" "<<temp->data<<":"<<temp->colour<<":";
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
  root=insertBtree(root,data,0);

  while(choice!=0)
  {
    cout<<"\nenter choice(1.Insert 2.print):";
    cin>>choice;

    switch (choice) {
      case 1: int data;
              cout<<"\nenter data:";
              cin>>data;
              //if(root!=NULL)
              //std::cout << "\n" <<root->data<<":l:"<<root->left<<":r: "<<root->right<< std::endl;
              root=insertBtree(root,data);
              break;
      case 2:printBtree(root);
              break;
    }
  }
  return 0;
}
