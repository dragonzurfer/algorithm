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


int main()
{
	ll n,i,j,ma=-1;
	cin>>n;
	ll dp[n],a[n];
	FOR1(i,n-1)
	{cin>>a[i];dp[i]=a[i];}

	FOR2(i,1,n-1)
	{
		FOR2(j,0,i)
		{
			if(a[i]>a[j]&&dp[j]+a[i]>dp[i])
				dp[i]=dp[j]+a[i];
			ma=max(dp[i],ma);
		}
	}

	cout<<ma;
	return 0;
}