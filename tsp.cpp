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
ll g[100][100],dp[100][100000],p[100][100000],n,npow;

int compute(int start,int set)
{
	ll res=INT_MAX,temp,i,j,masked;

	if(dp[start][set]!=-1)
		return dp[start][set];
	FOR1(i,n-1)
	{
		masked=set&((npow-1)-(1<<i));
		if(set!=masked)
		{
			temp=g[start][i]+compute(i,masked);
			if(temp<res)
				res=temp,p[start][set]=i;
		}
	}
	dp[start][set]=res;
	return res;
}
int tsp()
{
	ll i;
	npow=pow(2,n);
	FOR1(i,n-1)
	dp[i][0]=g[0][i];
	compute(0,npow-2);
	cout<<dp[0][npow-2];
	cout<<endl;

	int s=0,t=npow-2;
	while(p[s][t]>0)
	{
	    cout<<p[s][t];
	    s=p[s][t];
	    t=t&((npow-1)-(1<<s));
	}
}
int main()
{
	ll i,j;cin>>n;
	
	FOR1(i,99)
	FOR1(j,99999)
	dp[i][j]=-1,p[i][j]=-1;
	FOR1(i,n-1)
	FOR1(j,n-1)
	cin>>g[i][j];

	tsp();
	return 0;
}