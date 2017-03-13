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
	ll floors,eggs;
	cin>>eggs>>floors;
	ll dp[eggs+1][floors+1],i,j,l;
	clr(dp);

	FOR2(i,1,floors)
	dp[1][i]=i;
	FOR2(i,1,eggs){
	dp[i][1]=1;
	dp[i][0]=0;}

	FOR2(l,2,eggs)
	{
		FOR2(j,2,floors)
		{
			dp[l][j]=INT_MAX;
			FOR2(i,1,j)
			{
				// int t;cout<<endl<<l<<" "<<i<<" "<<j;cin>>t;
				dp[l][j]=min(dp[l][j],1+max(dp[l-1][i-1],dp[l][j-i]));

			}
		}
	}
	cout<<dp[eggs][floors];
	return 0;
}