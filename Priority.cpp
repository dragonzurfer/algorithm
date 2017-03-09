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
 	{cin>>p[i].atime>>p[i].btime>>p[i].priority;p[i].no=i;
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
 	
 	cout<<CT<<"->|p0|->";
 	int left=n;
 	
 	while(left)
 	{
 		if(F[Q.top().no]==1)
 		Q.pop();
 		process CP=Q.top();
 		bool swap=false;
 		FOR2(i,0,n-1)
 		{
 			if(F[tp[i].no]==0&&tp[i].btime>0&&tp[i].atime==CT)
 			{Q.push(tp[i]);P[tp[i].no]=1;}
 		}	
 			if(CP.no!=Q.top().no)
 			{
 				LST[CP.no]=CT;
 				cout<<".."<<CT<<"->p|"<<Q.top().no<<"|->";
 				WT[Q.top().no]=LST[Q.top().no]-CT;
 				swap=true;
 			}
 			process TP=Q.top();Q.pop();
 			TP.btime-=1;tp[TP.no].btime-=1;
 			CT+=1;Q.push(TP);
 			
 			if(Q.top().btime<=0&&F[Q.top().no]==0)
 			{
 				process EP=Q.top();Q.pop();
 				FT[EP.no]=CT;
 				cout<<";"<<CT;
 				if(Q.size()&&Q.top().no==EP.no)
 				Q.pop();
 				if(Q.size())
 				{
 				cout<<"->|p"<<Q.top().no<<"|->";
 				WT[Q.top().no]+=abs(LST[Q.top().no]-CT);
 				}
 				TT[EP.no]=CT-EP.atime;
 				left-=1;F[EP.no]=1;
 			}
 	}
 					
 	
 	int ATT=0,AWT=0;
 	FOR1(i,n-1)
 	{
 		ATT+=WT[i];
 		AWT+=TT[i];
 	}
 	cout<<"\nAWT:"<<(double)AWT/n;
 	cout<<"\nATT:"<<(double)ATT/n;
 	return 0;
 }
 


 	/*
 	5
1 3 2
2 4 3
3 3 4
10 5 1
11 3 2
*/
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
