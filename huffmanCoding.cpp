#include<bits/stdc++.h>

using namespace std;
#define REMOVE_SPACES(x) x.erase(std::remove(x.begin(), x.end(), ' '), x.end())
#define For(i,v,n) for(int i=v;i<n;i++)
#define For1(i,v) for(int i=v;i>=0;i--)
map<int,string>codes;
struct node{
  int val,freq;

  node *a[2];
};

typedef pair<int,node*> pp;
void printpq(node*root,string str)
{

  if (root!=NULL)
  {

  if(root->a[0]==NULL&&root->a[1]==NULL)
  codes[root->val]=str;
   printpq(root->a[0], str + "1");
   printpq(root->a[1], str + "0");}

}
void visualTree(node*p,int indent)
{

    if(p != NULL) {
        if(p->a[1]) {
            visualTree(p->a[1], indent+4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (p->a[1]) std::cout<<" /\n" << std::setw(indent) << ' ';
        std::cout<< p->val << "\n ";
        if(p->a[0]) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            visualTree(p->a[0], indent+4);
        }
    }
    return;
}
node* huffman(int c[],int len)
{
  int flag=0;
  map<int,int>m;
  priority_queue<pp>pq;
  For(i,0,len)
  {
    if(i!=0)
    if(c[i-1]!=c[i])
    {flag=1;}
    m[c[i]]=m[c[i]]+1;
  //  cout<<"count:"<<c[i]<<"->"<<m[c[i]]<<endl;
  }
  if(flag==0)
  {
    node* n= new node;
    n->val=0;
    n->a[1]=NULL;
    n->a[0]=NULL;return n;
  }
  map<int,int>check;
  For(i,0,len)
  {

    node* newnode=new node;
    newnode->val=c[i];
    newnode->a[0]=newnode->a[1]=NULL;
    newnode->freq=m[c[i]];
    //printf("NOd:%d\n",newnode->freq);
    if(m[c[i]]!=0)
    {
      if(check[c[i]]==0)
      {pq.push(make_pair(len-m[c[i]],newnode));check[c[i]]=1;}
      check[c[i]]=1;
    }

  }
 while (pq.size()!=1)
  {
    priority_queue<pp>q=pq;
    //cout<<endl;
    //while(!q.empty())
    //{
    //  cout<<" #"<<q.top().first<<"->"<<q.top().second->val;
    //  q.pop();
    //}
     node* node1;
     node* node2;
     node1=pq.top().second;
     pq.pop();
     node2=pq.top().second;
     pq.pop();
     node* pushBackNode=new node;
     pushBackNode->val=node1->val+node2->val;
     pushBackNode->a[0]=node1;pushBackNode->a[1]=node2;
     //printf("pushbackNOd:%d\n",node1->freq+node2->freq );
     pushBackNode->freq=node1->freq+node2->freq;
     pq.push(make_pair(len-pushBackNode->freq,pushBackNode));
  }
printpq(pq.top().second,"");
  return pq.top().second;
}


int main()
{
  int len,l,r,q;
  node*root;
  cin>>len;
  int c[len];

  For(i,0,len)
    cin>>c[i];

  cin>>q;
  while(q--)
  {
    cin>>l>>r;
    if(l!=r){
    int sub[r-l+1];
    for(int i=0;i<r-l+1;i++)
    sub[i]=c[l-1+i];
    root=huffman(sub,r-l+1);
    //visualTree(root,4);
    string s="";
    For(i,l-1,r)
    {

      //cout<<c[i]<<"->"<<codes[c[i]]<<endl;
      s=s+codes[c[i]];
    }


    cout<<s.length()<<endl;
  }else cout<<"0"<<endl;
}
  return 0;
}
