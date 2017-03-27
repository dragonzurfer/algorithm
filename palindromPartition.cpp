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
	ll n=s.length();
	bool p[n][n];
	ll c[n],i,j,l;
	
	FOR1(i,n-1)
	{
		FOR1(j,n-1)
		{
			p[i][j]=false;
		}
	}
	
	FOR1(i,n-1)
	p[i][i]=true;

	FOR2(l,2,n)
	{
		for(i=0;i<n-l+1;i++)
		{
			j=i+l-1;

			if(l==2)
				p[i][j]=(s[i]==s[j]);
			else 
				p[i][j]=(s[i]==s[j])&&p[i+1][j-1];
		}
	}

	FOR2(i,0,n-1)
	{
		if(p[0][i])
			c[i]=0;
		else
		{
			c[i]=INT_MAX;
			for(j=0;j<i;j++)
			{
				if(p[j+1][i]&&1+c[j]<c[i])
					c[i]=1+c[j];cut[i]=j;
			}
		}
	}
	
	cout<<c[n-1];
	return 0;
}