    #include <bits/stdc++.h>
    using namespace std;
    #define mp make_pair
    #define pb push_back
    #define lb lower_bound
    #define up upper_bound
    #define vll vector<ll>
    #define G vector<vll >
    #define F first
    #define S second
    #define pll pair<ll,ll>
    #define RFOR(i,a,b) for(int i=a;i>=b;i--)
    #define FOR(i,a,b) for(int i=a;i<=b;i++)
    #define endl '\n'
    #define clr(a) memset(a,0,sizeof(a))
    #define all(x) x.begin(),x.end()
    #define gc getchar
    #define pc putchar
    #define BEG(n) (2*n-2)
    #define END(n) (2*n-1)
    typedef long long ll;
	const int N = 100;
    vector<int>g[N];
	int t = 0,visited[N],pre[N],low[N];
	bool AP[N];
	void dfs(int u,int p)
    {
      visited[u] = 1;
      int child=0;
      pre[u] = low[u] = t++;
      for(auto v:g[u])
      {
        if(v == p)continue;
        if(visited[v])
        {
            low[u] = min(pre[v],low[u]);
        }
        else
        {
          dfs(v,u);
          low[u] = min(low[v],low[u]);
          if(pre[u]<=low[v]&&p!=-1)
          {
            AP[u] = true;
            child++;
          }
        }
      }
      if(p==-1&&child>1)
        AP[u] = true;
    }

    int main()
    {
  		clr(AP);clr(pre);clr(visited);clr(low);
      int n,e;
      cin>>n>>e;
      FOR(i,1,e)
      {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
      }
      dfs(1,-1);
      cout<<"{";
      FOR(i,1,n)
        if(AP[i])cout<<i<<",";
        cout<<"}";
      return 0;
    } 
