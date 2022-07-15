#include<iostream>  
using namespace std;

int main()
{
	int n, at[10],bt[10],i,j,qt,tot=0;
    int	ct[10],tat[10],wt[10],rn[10];
	float avg , avg1=0 ,avg2=0;
	string pn[10];
	 
	
	
	cout<<"\n Enter the number of process u want array";
	cin>>n;
	
	cout<<"\n Enter the arrival time ";
	for( i=0; i<n; i++)
	cin>>at[i];
	
	cout<<"\n Enter the burst time ";
	for( i=0; i<n; i++)
	{
	cin>>bt[i];
	rn[i]=bt[i];
	tot=tot+bt[i];
   }
	
	cout<<"\n Enter  the  name of the process";
	for(i=0; i<n; i++)
	cin>>pn[i];
	
	cout<<"\n Enter quantum time";
	cin>>qt;
	
	cout<<"\n The process Before sorting ";
	cout<<"\n"<<"process Name"<<"\t\t"<<"Arrival Time"<<"\t\t"<<"Burst Time"<<"\t"<<"reamining time \n";
	for( i=0; i<n; i++)
	cout<<"\n"<<pn[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<rn[i];
	
	for( i=0; i<n-1; i++){
		for( j=0; j<n-1-i; j++){
			if(at[j]>at[j+1]){
				swap(at[j],at[j+1]);
				swap(bt[j],bt[j+1]);
				swap(pn[j],pn[j+1]);
				swap(rn[j],rn[j+1]);
				
			}
		}
	}
	
	cout<<"\n The process After  sorting ";
    	cout<<"\n"<<"process Name"<<"\t\t"<<"Arrival Time"<<"\t\t"<<"Burst Time"<<"\t"<<"reamining time \n";
	    for( i=0; i<n; i++)
	    cout<<"\n"<<pn[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<rn[i];
        cout<<"\n\n";
	
	
    int count = 0;
  
    cout<<"0";
    	while(count<=tot)
    	{
    		for(i=0; i<n; i++)
    		{   
    			if(rn[i]>=qt && rn[i]!=0)
				{
					rn[i] = rn[i] - qt;
					ct[i] = count +qt; 
					
					//count = count+qt;
					
					//cout<<"\n"<<"process name"<<"\t\t"<<"completion Time"<<"\n";
					cout<<" | "<<pn[i]<<" | "<<ct[i];
					count = count+qt;
				 }
				 else if(rn[i]<qt && rn[i]!=0)
				 {
				    ct[i] = count + rn[i];
				    count = count + rn[i];
				 	rn[i] = 0;
				 
				 	//cout<<"\n"<<"process name"<<"\t\t"<<"completion Time"<<"\n";
					cout<<" | "<<pn[i]<<" | "<<ct[i];
					
				  } 
			}
		}
for(i=0;i<n;i++)
{
tat[i]=ct[i]-at[i];
wt[i] = tat[i]-bt[i];
avg1= avg1 +tat[i];
avg2 = avg2 + wt[i];

cout<<"\n"<<"process Name"<<"\t\t"<<"Turnarount time"<<"\t\t"<<"Waiting time.\n";
cout<<"\n"<<pn[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i];

}

cout<<"\n\n Avg tat is " << avg1/n;
cout<<"\n Avg tat is " << avg2/n;
return 0;		
}

  
   

