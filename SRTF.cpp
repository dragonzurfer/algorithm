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
	if(p1.atime==p2.atime)
		return p1.btime<p2.btime;
	return p1.atime<p2.atime;
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

	priority_queue<process,vector<process>,comp>Qt=Q;
	sort(p,p+n,cmp);

	while(!Qt.empty())
	cout<<Qt.top().atime<<"-"<<Qt.top().btime<<"-"<<Qt.top().priority<<"\n",Qt.pop();

	int finishing_time[n],turnaround_time[n],waiting_time[n],left=n;
	clr(finishing_time);clr(turnaround_time);clr(waiting_time);

	int currentTime=p[0].atime,laststoptime[n],finished[n];
	clr(finished);

	FOR1(i,n-1)
	laststoptime[p[i].no]=p[i].atime;
	Q.push(p[0]);
	int t;
	cout<<currentTime<<"->|p0|->";
	while(left)
	{
		process currentProcess=Q.top();

		FOR2(i,1,n-1)
		{
			if(finished[p[i].no]==0&&p[i].atime==currentTime)
			Q.push(p[i]);
		}
		// process newProcess=Q.top();
		if(currentProcess.no!=Q.top().no){
			laststoptime[currentProcess.no]=currentTime;
			cout<<":"<<currentTime<<"->|p"<<Q.top().no<<"|->";
			waiting_time[Q.top().no]+=laststoptime[Q.top().no]-currentTime;
		}


		// cout<<Q.top().no<<"-"<<Q.top().priority<<"-"<<Q.top().atime<<"-"<<Q.top().btime<<":"<<currentTime<<Q.size()<<endl;cin>>t;

		process tProcess=Q.top();Q.pop();
		tProcess.btime-=1;
		Q.push(tProcess);
		currentTime+=1;

		if(Q.top().btime==0&&finished[Q.top().no]==0){
			process endingProcess=Q.top();
			finishing_time[endingProcess.no]=currentTime;
			cout<<";"<<currentTime;Q.pop();
			if(Q.size()){
			cout<<"->|np"<<Q.top().no<<"|->";
			waiting_time[Q.top().no]+=abs(laststoptime[Q.top().no]-currentTime);
			}
			turnaround_time[endingProcess.no]=currentTime-endingProcess.atime;
			left-=1;finished[endingProcess.no]=1;
		}

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
//vishnu.tdeepak@gmail.com