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
#define LN 19
#define MAXN 400011
#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif

typedef long long ll;
bool VIS[MAXN];
ll read_ll() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    ll ret = 0;
    int neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

ll DP[LN][MAXN];
ll rootn,answer=0;
ll t=0;
ll st[MAXN],en[MAXN],id[2*MAXN+1],lvl[MAXN],cnt[MAXN],val[MAXN];

vll hashed(10000000,0);
vector<vll >g(MAXN);
struct query
{
  ll r,l,sp,ans;int index;
};

bool block(query a,query b)
{
    
  if(a.l/rootn<b.l/rootn)
      return true;
  else if(a.l/rootn>b.l/rootn)
      return false;
  return a.r<b.r;
}
bool cmp(query a,query b)
{
  return a.index<b.index;
}

void insert(ll pos)
{
 // cout<<"\nINSERT";
	cnt[id[pos]]+=1;
	hashed[val[id[pos]]]+=1;

	if(cnt[id[pos]]%2&&hashed[val[id[pos]]]==1)
		{answer+=1;}//cout<<"\nval incr for:"<<id[pos]<<" "<<answer;}

	if(cnt[id[pos]]%2==0)
		{answer-=1,hashed[val[id[pos]]]-=2;}//cout<<"\nval decr for:"<<id[pos]<<" "<<answer;}
}

void remove(ll pos)
{
 // cout<<"\nREMOVE";

	if(cnt[id[pos]]>0)
	cnt[id[pos]]-=1;
	else
	{return;}

    if(cnt[id[pos]]%2)
    	hashed[val[id[pos]]]+=1;
    else
    	hashed[val[id[pos]]]-=1;

    if(hashed[val[id[pos]]]==1)
    	{answer+=1;}//cout<<"\nval incr for:"<<id[pos]<<" "<<answer;}
    else if(hashed[val[id[pos]]]==0)
    	{answer-=1;}//cout<<"\nval decr for:"<<id[pos]<<" "<<answer;}
}

ll dfs(vector<vll>graph,ll v)
{
	st[v]=++t;
	id[t]=v;
		for (int i = 1; i < LN; i++) DP[i][v] = DP[i - 1][DP[i - 1][v]];
	for(auto&u:graph[v]){
		if(u==0)
			return 0;
			lvl[u]=lvl[v]+1,DP[0][u]=v,dfs(graph,u);
	}
	en[v]=++t;
	id[t]=v;
}
inline int lca2(int u, int v){
	if (lvl[u] > lvl[v]) swap(u, v);
	for (int i = LN - 1; i >= 0; i--)
		if (lvl[v] - (1 << i) >= lvl[u]) v = DP[i][v];
	if (u == v) return u;
	for (int i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}

// ll lca(vector<vll>graph,ll u,ll v)
// {
// 	while(p[u] != p[v]){
//         if(lvl[u] > lvl[v]){
//             u = p[u];
//         }
//         else{
//             v = p[v]; 
//         }
//     }
//     while(u != v){
//         if(lvl[u] > lvl[v]){
//             u = p[u];
//         }
//         else{
//             v = p[v]; 
//         }
//     }

//     return u ;
// }
void gao(int x) {
	if (VIS[id[x]]) {
		if (!(--hashed[id[x]]))	--answer;
	}
	else if ((++hashed[id[x]]) == 1)	++answer;
	VIS[id[x]] ^= 1;	
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll n,q,u,v,i,t;
	n=read_ll();
	q=read_ll();


	FOR1(i,n-1)
	val[i+1]=read_ll();

	FOR1(i,n-2)
	{
		u=read_ll();v=read_ll();
		g[u].pb(v);	
		g[v].pb(u);
	}
	lvl[1]=0;
	DP[0][1]=1;
	dfs(g,1);

	// cout<<endl<<endl;
	// for(auto&k:id)
	// 	cout<<k<<" ";
	// i=0;cout<<endl;
	// for(auto&k:id)
	// 	cout<<++i<<" ";
	// cout<<endl;
	query qa[q];
	FOR1(i,q-1)
	{
		qa[i].index=i;
		u=read_ll();v=read_ll();
		// cout<<lvl[u]<<" "<<lvl[v];
		if(st[u]>st[v])
			swap(u,v);
		ll c=lca2(u,v);
		// cout<<"lca:"<<c<<endl;int l;
		if(c==u)
		{
			qa[i].l=st[u];
			qa[i].r=st[v];
			qa[i].sp=0;
			// cout<<qa[i].l<<" "<<qa[i].r;cin>>l;
		}
		else
		{
			qa[i].l=en[u];
			qa[i].r=st[v];
			qa[i].sp=c;
		}
			// cout<<qa[i].l<<" "<<qa[i].r<<endl;
		if(qa[i].l>qa[i].r)
			swap(qa[i].l,qa[i].r);		
	}

	 rootn=sqrt(n);
	  sort(qa,qa+q,block);
	  ll currentL=0,currentR=0;

	  answer=0;
	    
	  FOR1(i,q-1)
	  {
	  	// cout<<"\n---------------------";
	  	// cout<<qa[i].l<<" "<<qa[i].r;
	      while(qa[i].l<currentL)
	          gao(--currentL);
	      while(currentR<qa[i].r)
	           gao(++currentR);
	      while(currentL<qa[i].l)
	          gao(currentL),currentL++;
	      while(currentR>qa[i].r)
	          gao(currentR),currentR--;
	      qa[qa[i].index].ans=answer-1;

	      if(qa[i].sp)
	      {
	      	if(hashed[val[id[qa[i].sp]]]==0)
	      		qa[qa[i].index].ans=answer+1-1;
	      }
	      // cout<<":"<<answer<<endl;
  	}
  	// cout<<endl<<endl;
  	// sort(qa,qa+q,cmp);
  	for(auto&qu:qa)
  		cout<<qu.ans<<endl;
  		// cout<<qu.l<<" "<<qu.r<<":"<<qu.ans<<" "<<qu.sp<<endl;

  	// int k;cin>>k;

	return 0;
}