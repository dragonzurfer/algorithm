#include<bits/stdc++.h>

using namespace std;
#define REMOVE_SPACES(x) x.erase(std::remove(x.begin(), x.end(), ' '), x.end())
#define For(i,v,n) for(int i=v;i<n;i++)
#define For1(i,v) for(int i=v;i>=0;i--)
map<string,string>codes;
struct node{
  string val;int freq;
  char *val2;
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
node* huffman(string c,int len)
{

  map<char,int>m;
  priority_queue<pp>pq;
  For(i,0,len)
  {
    if(c[i]!=' ')
    m[c[i]]=m[c[i]]+1;
  }

  For(i,0,len)
  {
    if(c[i]!=' ')
  { node* newnode=new node;
    newnode->val=c[i];
    newnode->a[0]=newnode->a[1]=NULL;
    newnode->freq=m[c[i]];
    if(m[c[i]]!=0)
    {
      pq.push(make_pair(len-m[c[i]],newnode));
      m.erase(c[i]);
    }
   }
  }
 while (pq.size()!=1)
  {
     node* node1;
     node* node2;
     node1=pq.top().second;
     pq.pop();
     node2=pq.top().second;
     pq.pop();
     node* pushBackNode=new node;
     pushBackNode->val=node1->val+node2->val;
     pushBackNode->a[0]=node1;pushBackNode->a[1]=node2;
     pushBackNode->freq=node1->freq+node2->freq;
     pq.push(make_pair(len-pushBackNode->freq,pushBackNode));
  }
printpq(pq.top().second,"");
  return pq.top().second;
}


int main()
{
  int len;

  cin>>len;
  string c;

  cin.ignore();
  getline(cin,c);
  REMOVE_SPACES(c);

  node*root;



  int l,r,q;
  string sub,s="";
  cin>>q;
  while(q--)
  {
    cin>>l>>r;
    sub=c.substr(l-1,r-l+1);
    root=huffman(sub,r-l+1);
    visualTree(root,4);
    cout<<"string:"<<sub;
    s="";
    For(i,0,r-l+1)
    {
      string firstLetter(1,sub[i]);
      //cout<<firstLetter<<"->"<<codes[firstLetter]<<endl;
      s=s+codes[firstLetter];
    }


    cout<<s.length()<<endl;
  }

  return 0;
}
