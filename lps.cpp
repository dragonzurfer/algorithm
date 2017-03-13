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
	string s;
	cin>>s;
	ll n=s.length(),i,j,l;
	ll dp[n][n];
	clr(dp);
	FOR1(i,n-1)
		dp[i][i]=1;

	FOR2(l,2,n)
	FOR1(i,n-l+1)
	{
		j=i+l-1;
			if(s[i]==s[j]&&l==2)
				dp[i][j]=2;
			if(s[i]==s[j])
				dp[i][j]=dp[i+1][j-1]+2;
			else
				dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
		
	}
	cout<<dp[0][n-1];
	return 0;
}