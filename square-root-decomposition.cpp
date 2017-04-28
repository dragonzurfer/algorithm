// mo's algorithm
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
ll rootn,answer=0;
vll a;
struct query
{
  ll r,l;
};

bool block(query a,query b)
{
    
  if(floor(a.l/rootn)<floor(b.l/rootn))
      return true;
  else if(floor(a.l/rootn)>floor(b.l/rootn))
      return false;
  return a.r<b.r;
}

void insert(ll pos)
{
    //cout<<endl<<"add "<<a[pos];
    answer+=a[pos];
}

void remove(ll pos)
{
    //cout<<endl<<"rem "<<a[pos];
    answer-=a[pos];    
}

int main()
{
  	ll i,n,t,q;cin>>n;
  	while(n--&&(cin>>t))
      a.pb(t);
    cin>>q;
  	query qa[q];
  
  	FOR1(i,q-1)
      cin>>qa[i].l>>qa[i].r;
  
  rootn=pow(a.size(),0.5);
  sort(qa,qa+q,block);
    
  //for(auto&k:qa)
  //  cout<<"("<<k.l<<","<<k.r<<"),";
  //cout<<"\nqueries";
 
  ll currentL=0,currentR=0;
  answer=a[0];
    
  FOR1(i,q-1)
  {
      //cout<<endl;
      while(currentL<qa[i].l)
          remove(currentL),currentL++;
      while(qa[i].l<currentL)
          insert(--currentL);
      while(currentR<qa[i].r)
           insert(++currentR);
      while(currentR>qa[i].r)
          remove(currentR),currentR--;
      //cout<<"answer:"<<answer;
      cout<<answer<<endl;
  }
  
    
  return 0;
}
