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
    cout<<" "<<temp->data<<":"<<temp->colour<<"  ";
    printBtree(temp->right);
  }
  return;
}

void rr(node*&root,node*&pt)
{
  node *pt_left = pt->left;
    cout<<"\nptleft:"<<pt_left->data;
    pt->left = pt_left->right;
    cout<<"\npt->left:"<<pt_left->right;
    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
      {  root = pt_left;cout<<endl<<"pt_left"<<pt_left->data;}
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
    cout<<"\npt_data:"<<pt->data<<":"<<pt->right->data<<":";

}
void rl(node*&root,node*&pt)
{
  node *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
    cout<<"ok";

}

void balanceTree(node* root,node* newNode)
{
  node*parent=NULL;
  node*grandparent=NULL;
  node*uncle=NULL;
  while(newNode!=root&&newNode->colour!=false&&newNode->parent->colour==true)
  {
    parent=newNode->parent;


      grandparent=parent->parent;

      //newNodes parent is left child of grandparent
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
            rl(root,parent);
            newNode=parent;//the old parent is now in the left hence its newNode
            parent=newNode->parent;//in rl we've changed the parent pointer of the old parent to the old newNode
            //this statement makes the old newNode the new parent
          }
          cout<<"\nnewNode:"<<newNode->data;
          rr(root,newNode);
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
              cout<<"\ndone inserting";
              balanceTree(root,newNode);
              cout<<"\n DOne! balancing";
              break;
      case 2:printBtree(root);
              cout<<"\nDone!";
              break;

    }
  }
  return 0;
}
