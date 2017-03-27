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
ll sum(ll freq[], ll i, ll j)
{
    ll s = 0;
    for (int k = i; k <=j; k++)
       s += freq[k];
    return s;
}

int main()
{
	ll n,i,j,l,k;
	cin>>n;
	ll a[n],f[n];
	FOR1(i,n-1)
	{
		cin>>a[i]>>f[i];
	}

	ll dp[n][n];
	clr(dp);
	FOR1(i,n-1)
	dp[i][i]=f[i];

	FOR2(l,2,n)
	{
		FOR2(i,0,n-l+1)
		{
			j=i+l-1;
			dp[i][j]=INT_MAX;
			FOR2(k,i,j)
			{
				int c=((k>i)?dp[i][k-1]:0)+((k<j)?dp[k+1][j]:0)+sum(f,i,j);
				if(c<dp[i][j])
					dp[i][j]=c;
			}
		}
	}

	cout<<dp[0][n-1];

	return 0;
}