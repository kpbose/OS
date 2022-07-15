#include<iostream>
using namespace std; 
int main() 
{ 
	int count,j,n,time,remain,flag=0,tq; 
	
	cout<<"Enter Total Process: "; 
	cin>>n; 
	remain=n; 
	int wait_time=0,turnaround_time=0,at[n],bt[n],rt[n];
	for(count=0;count<n;count++) 
	{		
		cout<<"Enter Arrival Time and Burst Time for Process No. "<<count+1<<" :"; 
		cin>>at[count]; 
		cin>>bt[count]; 
		rt[count]=bt[count]; 	//set (rt) remaining time = burst time
// we make changes in remaining time and burst time remains unchanged.
	} 
	cout<<"Enter Time Quantum:\t"; 
	cin>>tq; 
	cout<<"\n\nProcess\t|TurnaroundTime|Waiting Time\n\n"; 
	for(time=0,count=0;remain!=0;) 
	{ 
		if(rt[count]<=tq&&rt[count]>0) 
		{ 
			time+=rt[count]; 
			rt[count]=0; 
			flag=1; 
		} 
		else if(rt[count]>0) 
		{ 
			rt[count]-=tq; 
			time+=tq; 
		} 
		if(rt[count]==0 && flag==1) 
		{ 
			remain--; 
			cout<<"P["<<count+1<<"]\t|\t"<<time-at[count]<<"\t|\t"<<time-at[count]-bt[count]<<"\n"; 
	
			wait_time+=time-at[count]-bt[count]; 
			turnaround_time+=time-at[count]; 
			flag=0; 
		} 
		if(count==n-1) 
			count=0; 
		else if(at[count+1]<=time) 
			count++; 
		else
			count=0; 
	} 
	cout<<"\nAverage Waiting Time: "<<wait_time*1.0/n; 
	cout<<"Avg Turnaround Time : "<<turnaround_time*1.0/n; 
	// multiple by '1.0' to convert it into floating point values.
}
