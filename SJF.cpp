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
	int btime,atime,no,priority;
};
bool cmp(process p1,process p2)
{
 	return p1.btime<p2.btime;
}
struct comp
{
	bool operator()(process p1,process p2)
	{
		
			return p1.btime>p2.btime;
	}
};
int main()
{
	int n,i,avg_wtime=0,avg_ttime=0;
	cout<<"\n Number of Processes:";cin>>n;
	process p[n];
	priority_queue<process,vector<process>,comp>Q;

	FOR1(i,n-1)
	{
		cin>>p[i].atime>>p[i].btime>>p[i].priority;p[i].no=i;
		//Q.push(p[i]);
	}

	// priority_queue<process,vector<process>,comp>Qt=Q;
	sort(p,p+n,cmp);

	int finishing_time[n],turnaround_time[n],waiting_time[n],currentTime=0;
	clr(waiting_time);
	FOR1(i,n-1)
	{
		if(currentTime<p[i].atime)
			currentTime=p[i].atime;
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

	FOR1(i,n-1)
	{
		avg_ttime+=turnaround_time[i];
		avg_wtime+=waiting_time[i];
		// cout<<waiting_time[i]<<endl;
	}
	cout<<"\navg wait time:"<<(double)avg_wtime/n;
	cout<<"\navg turnaround time:"<<(double)avg_ttime/n;
	return 0;
}
