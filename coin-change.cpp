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
	int n,i,j,amt;cin>>n;
	int c[n];
	FOR1(i,n-1)
		cin>>c[i];
	cin>>amt;
	int dp[n+1][amt];
	clr(dp);
	FOR1(i,n-1)
		dp[0][i]=1;

	FOR2(i,1,n-1)
	{
		FOR2(j,0,amt-1)
		{
			if(c[i]<=i)
			dp[i][j]+=(dp[i-c[j]][j]);
			if(j>0)
			dp[i][j]+=(dp[i][j-1]);
		}
	}
	cout<<"Number of ways:"<<dp[n][amt-1];
	return 0;
}