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
ll N;

template<class T>
struct BIT
{
    T *bit;int n;
    BIT(int n):n(n){bit=(T*)calloc(n+1,sizeof(T));}
    ~BIT(){free(bit);}
    void reset(){
    	memset(bit,0,sizeof(T)*(n+1));
    }
    void update(int u,T v){
    	while(u<=n)
    		bit[u]=(bit[u]+v),u+=(u&-u);
    }
    void rangeUpdate(int u, int v, T x){
    	update(u, x);
    	update(v + 1, -x);
    }
    T query(int u){
    	T ret=0;
    	while(u)
    		ret=(ret + bit[u]),u-=(u&-u);
    	return ret;
    }
    T query(int u,int v)
    {
    	return (query(v)-query(u-1));
    }
    T querySingle(int u)
    {
    	T sum=bit[u];
    	if(u>0){
    		int z=u-(u&-u);
    		u--;
    		while(u!=z)
    		{
    			sum-=bit[u];
    			u-=(u&-u);
    		}
    	}
    	return sum;
    }    
};

template<class T>
struct RBIT
{
    T *bit1,*bit2;int n;
    RBIT(int n):n(n){bit1=(T*)calloc(n+1,sizeof(T));bit2=(T*)calloc(n+1,sizeof(T));}
    ~RBIT(){free(bit1);free(bit2);}
    void reset(){
    	memset(bit1,0,sizeof(T)*(n+1));
    	memset(bit2,0,sizeof(T)*(n+1));
    }
    void update(T *bit,int u,T v){
    	while(u<=n)
    		bit[u]=(bit[u]+v),u+=(u&-u);
    }
    T read1(int u){
    	T ret=0;
    	while(u)
    		ret=(ret + bit1[u]),u-=(u&-u);
    	return ret;
    }
    T read2(int u){
    	T ret=0;
    	while(u)
    		ret=(ret + bit2[u]),u-=(u&-u);
    	return ret;
    }
    T query(int u)
    {
    	return read1(u)*u-read2(u);
    }
    void RUpdate(int a, int b, T v){
	  update(bit1, a, v); 	
	  update(bit1, b + 1, -v);	
	  update(bit2, a, v * (a-1));	
	  update(bit2, b + 1, -v * b);
    	
    }
    T Rquery(int u,int v)
    {
    	return (query(v)-query(u-1));
    }    
};

int main()
{
	ll q,t,l,r,v;cin>>N>>q;
	RBIT<ll> Rft(N);
	while(q--)
	{
		cin>>t;
		if(t==1)
		{
			cin>>l>>r;
			cout<<Rft.Rquery(l,r)<<endl;
		}
		else if(t==2)
		{
			cin>>l>>r>>v;Rft.RUpdate(l,r,v);
		}
	}
	cout<<"\n-------------\n";
	cin>>q;
	BIT<ll> ft(N);
	while(q--)
	{
		cin>>t;
		if(t==1)
		{
			cin>>l>>r;
			cout<<ft.query(l,r)<<endl;
		}
		else if(t==2)
		{
			cin>>l;
			cout<<ft.query(l)<<endl;
		}
		else if(t==3)
		{
			cin>>l>>v;
			ft.update(l,v);
		}
		else if(t==4)
		{
			cin>>l>>r>>v;
			ft.rangeUpdate(l,r,v);
		}
	}
	return 0;
}