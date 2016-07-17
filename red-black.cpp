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

node* insertBtree(node*&n,node*&d,int c=1)
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
        return n;
}

void printBtree(node* temp,node*root) {
  if(temp!=NULL)
  {
    printBtree(temp->left,root);
    cout<<" "<<temp->data;
    printBtree(temp->right,root);
  }
  return;
}
void visualTree(node*p,int indent)
{

    if(p != NULL) {
        if(p->right) {
            visualTree(p->right, indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->data << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            visualTree(p->left, indent+4);
        }
    }
    return;
}
void rr(node*&root,node*&pt)
{
  node*parent=NULL;
  node*pt_right=NULL;
  if(pt!=root)
    parent=pt->parent;
  else
    {cout<<"\n!sorry can't right rotate at root!";return;}

  pt_right=pt->right;
  pt->parent=parent->parent;
  if(parent!=root)
  {
    if(parent==parent->parent->right)
      parent->parent->right=pt;
    else
      parent->parent->left=pt;
  }
  else{
    pt->colour=false;
    root=pt;
  }
  parent->parent=pt;
  pt->right=parent;
  parent->left=pt_right;
  if(pt_right!=NULL)
  pt_right->parent=parent;

}
void rl(node*&root,node*&pt)
{
  node*parent=NULL;
  node*pt_left=NULL;
  if(pt!=root)
    parent=pt->parent;
  else
    {cout<<"\n!sorry can't left rotate at root!";return;}

  pt_left=pt->left;
  pt->parent=parent->parent;
  if(parent!=root)
  {
    if(parent==parent->parent->right)
      parent->parent->right=pt;
    else
      parent->parent->left=pt;
  }
  else{
    pt->colour=false;
    root=pt;
  }
  parent->parent=pt;
  pt->left=parent;
  parent->right=pt_left;
  if(pt_left!=NULL)
  pt_left->parent=parent;

}

void balanceTree(node*&root,node*&newNode)
{
  node*parent=NULL;
  node*grandparent=NULL;
  node*uncle=NULL;
  while(newNode!=root&&newNode->colour!=false&&newNode->parent->colour==true)
  {
    parent=newNode->parent;


      grandparent=parent->parent;

      if(parent==grandparent->left)
      {
        uncle=grandparent->right;

        if((uncle!=NULL)&&uncle->colour==true)
        {
          if(grandparent!=root)
          grandparent->colour=true;

          parent->colour=false;
          uncle->colour=false;
          newNode=grandparent;
        }
        else
        {
          if(newNode==parent->right)
          {
            rl(root,newNode);
            newNode=parent;
            parent=newNode->parent;

          }

          rr(root,parent);
          parent->colour=false;
          grandparent->colour=true;
          newNode=parent;

        }

      }
      else//case B
      {
        uncle=grandparent->left;
        if((uncle!=NULL)&&uncle->colour==true)
        {
          if(grandparent!=root)
          grandparent->colour=true;

          parent->colour=false;
          uncle->colour=false;
          newNode=grandparent;
        }
        else
        {
          if(newNode==parent->left)
          {
            rr(root,newNode);
            newNode=parent;
            parent=newNode->parent;

          }

          rl(root,parent);
          parent->colour=false;
          grandparent->colour=true;
          newNode=parent;

        }

      }



  }


}


int main()
{
  node *root=NULL;
  int choice=1;
  int data;

  cout<<"\nenter root data:";
  cin>>data;
  node *newroot=create(data);
  root=insertBtree(root,newroot,0);

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
              balanceTree(root,newNode);
              break;
      case 2:printBtree(root,root);
              break;
      case 3:visualTree(root,1);
              break;

    }
  }
  return 0;
}
