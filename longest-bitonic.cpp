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
	ll n,i,j,t;cin>>n;
	ll dp1[n],dp2[n];
	vector<ll> a;
	FOR1(i,n-1)
	{cin>>t;a.pb(t);dp1[i]=1,dp2[i]=1;}
	
	FOR2(i,1,n-1)
	{
		FOR1(j,i)
		{
			if(a[i]>a[j]&&1+dp1[j]>dp1[i])
				dp1[i]=dp1[j]+1;
		}
	}

	reverse(all(a));

	FOR2(i,1,n-1)
	{
		FOR1(j,i)
		{
			if(a[i]>a[j]&&1+dp2[j]>dp2[i])
				dp2[i]=dp2[j]+1;
		}
	}

	ll dp3[n],ma=-1;
	FOR1(i,n-1)
	dp3[i]=dp1[i]+dp2[i]-1,ma=max(dp3[i],ma);

	cout<<ma;
	return 0;
}