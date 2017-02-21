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

int maxmialMatch(list<ll>graph[],ll n)
{
	set<pll> matching;
	bool matchedVertex[n];
	memset(matchedVertex,false,sizeof(matchedVertex));
	for(ll v=1;v<n;v++)
	for(auto&u:graph[v])
	{
		if(matchedVertex[v])
			break;
		if(matching.count(mp(v,u))==0&&!matchedVertex[u])
		{
			matching.insert(mp(v,u));
			matchedVertex[v]=true;
			matchedVertex[u]=true;
		}
	}
	// testing
	for(auto&s:matching)
		cout<<"("<<s.F<<","<<s.S<<")"<<endl;
}

int main()
{
	ll n,e,i;
	cin>>n>>e;
	list<ll>graph[n];
	FOR1(i,e-1)
	{
		ll u,v;
		cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	maxmialMatch(graph,n);
	return 0;
}