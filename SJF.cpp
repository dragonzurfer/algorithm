 #include<bits/stdc++.h>
 
 #define FOR1(a,b) for(a=0;a<=b;a++)
 #define FOR2(a,b,c) for(a=b;a<=c;a++)
 #define clr(a) memset(a,0,sizeof(a))
 
 using namespace std;
 struct process
 {
 int atime,btime,no;
 };
 bool cmp(process a,process b)
 {
 return a.btime<b.btime;
 }
 
 int main()
 {
 	int n,i;
 	cout<<"\n No. of processses:";cin>>n;
 	
 	process p[n];
 	
 	FOR1(i,n-1)
 	{cin>>p[i].atime>>p[i].btime;p[i].no=i;}
 	
 	sort(p,p+n,cmp);
 	int FT[n],TT[n],WT[n],CT=0;
 	cout<<"\new order \n no at bt\n";
 	FOR1(i,n-1)
 	cout<<p[i].no<<" "<<p[i].atime<<" "<<p[i].btime<<endl;
 	FOR1(i,n-1)
 	{
 	
 		if(CT<p[i].atime)
 			CT=p[i].atime,WT[i]=0;
 		else
 			WT[i]=CT-p[i].atime;
 			
 		FT[i]=CT+p[i].btime;
 		TT[i]=FT[i]-p[i].atime;
 		
 		if(i!=0&&FT[i-1])
 			cout<<".."<<CT<<"->|p"<<p[i].no<<"|->"<<FT[i];	
 		else
 		{
 			if(i==0)
 				cout<<CT;
 			cout<<"->|p"<<p[i].no<<"|->"<<FT[i];
 		}
 		CT+=p[i].btime;
 	}
 	int ATT=0,AWT=0;
 	FOR1(i,n-1)
 	{
 		AWT+=WT[i];
 		ATT+=TT[i];
 	}
 	cout<<"\nAWT:"<<(double)AWT/n;
 	cout<<"\nATT:"<<(double)ATT/n;
 	return 0;
 }
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
