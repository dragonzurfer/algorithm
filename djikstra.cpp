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

ll n,dist[10000];
map<pair<ll,ll>,ll>l;


struct comp
{
 	bool operator()(ll a,ll b)
	{
	return dist[a]>dist[b];
	}
 };

void djikstra(vector<vll >graph,ll s)
{
	ll i,prev[n];
	priority_queue<ll,vector<ll>,comp>Q;
	FOR1(i,n-1)
	{
		if(i==s)
			{dist[i]=0;prev[i]=-1;}
		else
			{dist[i]=10000;prev[i]=-1;}
			Q.push(i);
	}
	
	while(!Q.empty())
	{
		ll u=Q.top();Q.pop();
		for(auto&v:graph[u])
		{
			ll alt=dist[u]+l[mp(u,v)];
			if(alt<dist[v])
				dist[v]=alt,prev[v]=u;	
		}
	}

	FOR1(i,n-1)
	{
		cout<<endl<<"dist to "<<i<<":"<<dist[i];
	}

}

int main()
{
	ll i,e;cin>>n>>e;
	vector<vll >graph(n);

	FOR1(i,e-1)
	{
		ll u,v,w;cin>>u>>v>>w;
		graph[u].pb(v);
		l[mp(u,v)]=w;// use unordered map for efficiency
	}
	ll s;cin>>s;
	djikstra(graph,s);
	return 0;
}