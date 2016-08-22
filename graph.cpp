#include<bits/stdc++.h>

using namespace std;

class graph
{
  int NumberOfVertices;
  list<int> *adj;
public:
  graph(int v);
  void addNode(int v,int e);
  void bfs(int s);
};

graph::graph(int v)
{
  this->NumberOfVertices=v;
  adj=new list<int>[NumberOfVertices];
}

void graph::addNode(int v,int e)
{
  adj[v].push_back(e);
}
void graph::bfs(int s)
{
  int k=1;
  bool *visited=new bool[NumberOfVertices];
  for(int i=0;i<NumberOfVertices;i++)
  visited[i]=false;
  list<int>queue;
  visited[s]=true;
  queue.push_back(s);
  list<int>::iterator i;
  while(!queue.empty())
  {
    s=queue.front();
    cout<<s<<" ";
    queue.pop_front();
    for(i=adj[s].begin();i!=adj[s].end();++i)
    {
      if(visited[*i]==false)
      {
      visited[*i]=true;
      queue.push_back(*i);
      }
    }
    for(i=queue.begin();i!=queue.end();++i)
    {
      cout<<"\nAfter State:"<<k;++k;
      cout<<"\nqueue:"<<*i<<" visited"<<visited[*i];
    }

  }
}

int main()
{
  graph g(4);
  g.addNode(0,1);
  g.addNode(0,2);
  g.addNode(1,2);
  g.addNode(2,0);
  g.addNode(2,3);
  g.addNode(3,3);
  g.bfs(2);
  return 0;
}
