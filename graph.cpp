#include<bits/stdc++.h>

using namespace std;

class graph
{
  long long NumberOfVertices;
  list<long long> *adj;
public:
  graph(long long v);
  void addNode(long long v,long long e);
  void bfs(long long find,long long s);
};

graph::graph(long long v)
{
  this->NumberOfVertices=v;
  adj=new list<long long>[NumberOfVertices];
}

void graph::addNode(long long v,long long e)
{
  adj[v].push_back(e);
}
void graph::bfs(long long s)
{
  long long k=1;
  bool *visited=new bool[NumberOfVertices];
  for(long long i=0;i<NumberOfVertices;i++)
  visited[i]=false;
  list<long long>queue;
  visited[s]=true;
  queue.push_back(s);
  list<long long>::iterator i;
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

long long main()
{
  graph g(4);

  g.addNode(0,1);
  g.addNode(0,2);
  g.addNode(1,2);
  g.addNode(2,0);
  g.addNode(2,3);
  g.addNode(3,3);
  long long dist=g.bfs(0,2);
  dist=g.bfs(1,2);
  return 0;
}
