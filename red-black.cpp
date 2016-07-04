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
  node* n=new node;
  n->data=d;
  n->colour=false;
  n->parent=NULL;
  n->right=NULL;
  n->left=NULL;
  return n;
}
node* insertBtree(node*n,int d)
{
  if(n==NULL)
  {
    std::cout << "\nNULL:" << std::endl;
    return create(d);
  }

    if(d<=n->data)
        {n->left=insertBtree(n->left,d);std::cout << "left" << std::endl;}
      else
        {n->right=insertBtree(n->right,d);std::cout << "right" << std::endl;}
        return n;
}

void printBtree(node* temp) {
  if(temp!=NULL)
  {
    printBtree(temp->left);
    cout<<" "<<temp->data;
    printBtree(temp->right);
  }
  return;
}

int main()
{
  node *root=NULL;
  int choice;
  while(choice!=0)
  {
    cout<<"\nenter choice(1.Insert 2.print):";
    cin>>choice;
    switch (choice) {
      case 1: int data;
              cout<<"\nenter data:";
              cin>>data;
              if(root!=NULL)
              std::cout << "\n" <<root->data<<":l:"<<root->left<<":r: "<<root->right<< std::endl;
              root=insertBtree(root,data);
              break;
      case 2:printBtree(root);
              break;
    }
  }
  return 0;
}
