#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define pll pair<ll,ll>
#define FOR1(i,a) for(i=0;i<=a;i++)
#define FOR2(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
typedef long long ll;
ll n,e;

bool bfs(list<ll>graph[],map<pll,ll>residual,bool visited[],ll parent[],ll v,ll t)
{
	queue<ll> q;
	q.push(v);
	while(!q.empty())
	{
		ll v=q.front();q.pop();
		visited[v]=true;
		for(auto&u:graph[v]){
			if(!visited[u]&&residual[mp(v,u)]>0){
				q.push(u);
				parent[u]=v;
			}
		}
	}
	return (visited[t]==true);
}

int max_flow(list<ll>graph[],map<pll,ll>residual,ll s,ll t)
{
	ll parent[n+1],bottle_neck,maxflow=0,u,v,i;
	clr(parent);
	bool visited[n+1]={false};

	while(bfs(graph,residual,visited,parent,s,t))
	{
		v=t;bottle_neck=INT_MAX;
		while(v!=s)
		{
			u=parent[v];
			bottle_neck=min(bottle_neck,residual[mp(u,v)]);
			v=u;
		}
		v=t;
		while(v!=s)
		{
			u=parent[v];
			residual[mp(u,v)]-=bottle_neck;
			if(residual[mp(v,u)]==0)
				graph[v].pb(u);
			residual[mp(v,u)]+=bottle_neck;
			v=u;
		}
		maxflow+=bottle_neck;
		clr(parent);
		memset(visited,false,sizeof(visited));
	}
	return maxflow;
}

int main()
{
	ll s,t,u,v,c,i;
	cin>>n>>e;
    list<ll>graph[n+1];
    map<pll,ll>residual;

    FOR1(i,e-1)
    {
    	cin>>u>>v>>c;
    	graph[u].pb(v);
    	residual.insert(mp(mp(u,v),c));
    }
    cin>>s>>t;
    cout<<max_flow(graph,residual,s,t);
    return 0;
}
