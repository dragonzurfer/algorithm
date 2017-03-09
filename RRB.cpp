#include<bits/stdc++.h>
 
 #define FOR1(a,b) for(a=0;a<=b;a++)
 #define FOR2(a,b,c) for(a=b;a<=c;a++)
 #define clr(a) memset(a,0,sizeof(a))
 
 using namespace std;
 struct process
 {
 int atime,btime,no,priority;
 };
 bool cmp(process a,process b)
 {
 return a.atime<b.atime;
 }
 struct comp
 {
 	bool operator()(process a,process b)
 	{
 		if(a.priority==b.priority)
 		return a.btime>b.btime;
 	return a.priority<b.priority;
 	}
 };
 
 int main()
 {
 	int n,i;
 	cout<<"\n No. of processses:";cin>>n;
 	
 	process p[n],tp[n];
 	
 	FOR1(i,n-1)
 	{cin>>p[i].atime>>p[i].btime;p[i].no=i;
 		tp[i]=p[i];
 	}
 	
 	
 	int FT[n],TT[n],WT[n],LST[n],CT,F[n],P[n];
 	
 	clr(FT);clr(TT);clr(WT);clr(F);clr(P);
 	sort(p,p+n,cmp);
 	FOR1(i,n-1)
 	LST[p[i].no]=p[i].atime;
 	CT=p[0].atime;
 	priority_queue<process,vector<process>,comp>Q;
 	Q.push(p[0]);
 	int quanta;cin>>quanta;
 	cout<<CT;//<<"->|p0|->";
 	int left=n;
 	i=0;
 	while(left)
 	{
 		i=i%n;
 		//cout<<"\n"<<p[i].no<<"-"<<p[i].btime;int t;cin>>t;
 		if(p[i].btime>0&&p[i].atime<=CT)
 		{
 		cout<<"->|p"<<i<<"|->"<<CT+quanta;
 		if(p[i].btime<=quanta)
 			{p[i].btime=0;WT[p[i].no]+=CT-LST[p[i].no];FT[p[i].no]=CT+p[i].btime;}
 		else{
 		   p[i].btime-=quanta;
 		 	WT[p[i].no]+=CT-LST[p[i].no];
 		 }
 		 if(p[i].btime==0&&F[p[i].no]==0)
 		 {
 		   F[p[i].no]==1;left-=1;
 		   if(FT[p[i].no]!=0)
 		   FT[p[i].no]=CT+quanta;
 		   TT[p[i].no]=FT[p[i].no]-p[i].atime;
 		 }
 		CT+=quanta;
 		LST[p[i].no]=CT;
 		}
 	i+=1;
 	}
 					
 	cout<<endl;
 	int ATT=0,AWT=0;
 	FOR1(i,n-1)
 	{
 		AWT+=WT[i];
 		ATT+=TT[i];
 		cout<<WT[i]<<endl;
 	}
 	cout<<"\nAWT:"<<(double)AWT/n;
 	cout<<"\nATT:"<<(double)ATT/n;
 	return 0;
 }
