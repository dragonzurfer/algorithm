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

struct process
{
	int btime,atime,no;
};
bool cmp(process p1,process p2)
{
	if(p1.atime==p2.atime)
		return p1.btime<p2.btime;
	return p1.atime<p2.atime;
}
int main()
{
	int n,i;
	cout<<"\n Number of Processes:";cin>>n;
	process p[n];
	FOR1(i,n-1)
	{cin>>p[i].atime>>p[i].btime;p[i].no=i;}

	sort(p,p+n,cmp);
	FOR1(i,n-1)
	cout<<p[i].atime<<"-"<<p[i].btime<<"\n";
	int finishing_time[n],turnaround_time[n],waiting_time[n],currentTime=0;
	FOR1(i,n-1)
	{
		
		if(currentTime<p[i].atime)
			currentTime=p[i].atime,waiting_time[i]=0;
		else
			waiting_time[i]=currentTime-p[i].atime;

		finishing_time[i]=currentTime+p[i].btime;
		turnaround_time[i]=finishing_time[i]-p[i].atime;
		if(i!=0&&currentTime!=finishing_time[i-1])
			cout<<".."<<currentTime<<"->|p"<<p[i].no<<"("<<p[i].atime<<")|->"<<finishing_time[i]<<"";
		else
		{
			if(i==0)
				cout<<currentTime;
			cout<<"->|p"<<p[i].no<<"("<<p[i].atime<<")|->"<<finishing_time[i]<<"";
		}
		currentTime+=p[i].btime;
	}

	int avg_wtime=0,avg_ttime=0;

	FOR1(i,n-1)
	{
		avg_ttime+=turnaround_time[i];
		avg_wtime+=waiting_time[i];
		// cout<<turnaround_time[i]<<endl;
	}
	cout<<"\navg wait time:"<<(double)avg_wtime/n;
	cout<<"\navg turnaround time:"<<(double)avg_ttime/n;
	return 0;
}