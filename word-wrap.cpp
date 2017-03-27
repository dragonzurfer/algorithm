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

int print (ll p[], ll n)
{
    ll k;
    if (p[n] == 1)
        k = 1;
    else
        k = print (p, p[n]-1) + 1;
    // printf ("Line number %d: From word no. %d to %d \n", k, p[n], n);
    cout<<"\nLine number "<<k<<": From word no."<<p[n]<<" to "<<n;
    return k;
}


int main()
{
	vector<ll>s;
	ll n,i,j,w;
	cin>>n;
	cin>>w;
	s.pb(-1);
	FOR2(i,1,n)
	{
		string str;cin>>str;
		s.pb(str.length());
	}
	ll extras[n+1][n+1]={0},lc[n+1][n+1];
	FOR2(i,1,n)
	{
		extras[i][i]=w-s[i];
		FOR2(j,i+1,n)
		{
			extras[i][j]=extras[i][j-1]-s[j]-1;
		}
	}

	FOR2(i,1,n)
	{
		FOR2(j,1,n)
		{
			if(extras[i][j]<0)
				lc[i][j]=10000;
			else
				lc[i][j]=extras[i][j]*extras[i][j];
		}
	}
	ll c[n+1]={0};
	ll p[n+1][n+1],pp[n+1];
	clr(p);
	c[0]=0;
	FOR2(i,1,n)
	{
		c[i]=100000;
		FOR2(j,1,i)
		{
			if(c[j-1]+lc[j][i]<c[i])
			{
			c[i]=c[j-1]+lc[j][i];
			p[j][i]=1;
			pp[i]=j;
			}
		}
	}
	print(pp,n);
	cout<<c[n];
	return 0;
}