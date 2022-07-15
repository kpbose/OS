/*#include<iostream>
#include<string.h>
using namespace std;
int main()
{
int i,j,n;
cout<<"enter the number of processes \n ";
cin>>n;
int at[n],bt[n],ct[n],wt[n],tt[n];
string pn[n]; 
    for(i=0;i<n;i++)
   {
    cout<<"enter the processes name ,arrival time and burst time \n ";
 cin>>pn[i]>>at[i]>>bt[i];
}
cout<<"PROCESS NAME \tARIVAL TIME  \tBURST TIME \n";
    for(i=0;i<n;i++)
    cout<<"\t"<<pn[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\n";
    for(i=0;i<n;i++)
    {
for(j=i;j<n-1;j++)
     {
     string k;
int t;
if(at[i]>at[j+1])
     {t=at[i];
      at[i]=at[j+1];
      at[j+1]=t;      
      k=pn[i];
      pn[i]=pn[j+1];
      pn[j+1]=k;
      t=bt[i];
      bt[i]=bt[j+1];
      bt[j+1]=t;
}
}
}
    cout<<"arranged processes \n ";
   cout<<"PROCESS NAME \t ARIVAL TIME \t BURST TIME  \n";
    for(i=0;i<n;i++)
    cout<<"\t"<<pn[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\n";
cout<<"COMPLETION TIME \n";
for(i=0;i<n;i++)
{ct[-1]=0;
ct[i]=ct[i-1]+bt[i];
}
cout<<"PROCESS NAME \t COMPLETION TIME \n";
   for(i=0;i<n;i++)
    cout<<"\t"<<pn[i]<<"\t\t"<<ct[i]<<"\n";    
    cout<<"TURN AROUND TIME \n";
    for(i=0;i<n;i++)
    {
     tt[i]=ct[i]-at[i];
     wt[i]=tt[i]-bt[i];
}
cout<<"PROCESS NAME \t ARIVAL TIME \t BURST TIME \t COMPLETION TIME \t TURN AROUND TIME \t WAITING TIME \t \n";
for(i=0;i<n;i++)
{
cout<<"\t"<<pn[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<ct[i]<<"\t\t\t"<<tt[i]<<"\t\t\t"<<wt[i]<<"\n";
}
int att=0,awt=0;
for(i=0;i<n;i++)
{ att=att+tt[i];
  awt=awt+wt[i];
}
cout<<"average turn around time = "<<"\t"<<((float)att/n)<<"\n"<<"average waiting  time = "<<"\t"<<((float)awt/n);
return 0; 
}

















#include<iostream>
#include<string.h>
using namespace std;
int getmin(int i,int n,int bt[])
{
int j,d,min=10000;
for(j=i;j<n;j++)
{
if(min>bt[j])
{min=bt[j];
d=j;
}
}
return d;
}
int main()
{
int i,j,n;
cout<<"enter the number of processes \n ";
cin>>n;
int at[n],bt[n],ct[n],wt[n],tt[n];
string pn[n];
cout<<"enter the processes name ,arrival time and burst time \n ";
    for(i=0;i<n;i++)
    cin>>pn[i]>>at[i]>>bt[i];
    cout<<"PROCESS NAME \tARIVAL TIME  \tBURST TIME \n";
    for(i=0;i<n;i++)
    cout<<"\t"<<pn[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\n";
    for(i=0;i<n;i++)
    {
     for(j=i;j<n-1;j++)
     {
     string k;
int t;
     if(at[i]>at[j+1])
     {t=at[i];
      at[i]=at[j+1];
      at[j+1]=t;
      k=pn[i];
      pn[i]=pn[j+1];
      pn[j+1]=k;
      t=bt[i];
      bt[i]=bt[j+1];
      bt[j+1]=t;
}
}
}
   cout<<"arranged processes \n ";
    cout<<"PROCESS NAME \t ARIVAL TIME \t BURST TIME  \n";
    for(i=0;i<n;i++)
    cout<<"\t"<<pn[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\n";
cout<<"COMPLETION TIME \n";
ct[0]=bt[0];
for(i=1;i<n;i++)
{
if(ct[i-1]>at[i])
{ int d;
d=getmin(i,n,bt);
string k;
int t;
     t=at[i];
      at[i]=at[d];
      at[d]=t;
      k=pn[i];
      pn[i]=pn[d];
      pn[d]=k;
      t=bt[i];
      bt[i]=bt[d];
      bt[d]=t;
ct[i]=ct[i-1]+bt[i];
}
    else{
    ct[i]=ct[i-1]+bt[i];
}
}
    cout<<"PROCESS NAME \t COMPLETION TIME \n";
    for(i=0;i<n;i++)
    cout<<"\t"<<pn[i]<<"\t\t"<<ct[i]<<"\n";
    cout<<"TURN AROUND TIME \n";
    for(i=0;i<n;i++)
    {
     tt[i]=ct[i]-at[i];
     wt[i]=tt[i]-bt[i];
}
cout<<"PROCESS NAME \t ARIVAL TIME \t BURST TIME \t COMPLETION TIME \t TURN AROUND TIME \t WAITING TIME \t \n";
for(i=0;i<n;i++)
{
cout<<"\t"<<pn[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<ct[i]<<"\t\t\t"<<tt[i]<<"\t\t"<<wt[i]<<"\n";
} 
return 0; 
}



*/







#include<iostream>
#include<string.h>
using namespace std;
int getmin(int i,int n,int p[])
{
int j,d,min=10000;
for(j=i;j<n;j++)
{
if(min>p[j])
{min=p[j];
d=j;
}
}
return d;
}
int main()
{
int i,j,n;
cout<<"enter the number of processes \n ";
cin>>n;
int at[n],bt[n],p[n],ct[n],wt[n],tt[n];
string pn[n];
cout<<"enter the processes name ,arrival time, burst time  and priority\n ";
    for(i=0;i<n;i++)
  {   cout<<"enter for "<<i+1;
  cin>>pn[i]>>at[i]>>bt[i]>>p[i];
  }
    cout<<"PROCESS NAME \tARIVAL TIME  \tBURST TIME \tPRIORITY \n";
    for(i=0;i<n;i++)
    cout<<"\t"<<pn[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<p[i]<<"\n";
    for(i=0;i<n;i++)
    {
     for(j=i;j<n-1;j++)
     {
     string k;
int t;
     if(at[i]>at[j+1])
     {t=at[i];
      at[i]=at[j+1];
      at[j+1]=t;
     k=pn[i];
      pn[i]=pn[j+1];
      pn[j+1]=k;
      t=bt[i];
      bt[i]=bt[j+1];
      bt[j+1]=t;
      t=p[i];
      p[i]=p[j+1];
      p[j+1]=t;
}
}
}
    cout<<"arranged processes \n ";
    cout<<"PROCESS NAME \t ARIVAL TIME \t BURST TIME \tPRIORITY \n";
    for(i=0;i<n;i++)
    cout<<"\t"<<pn[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<p[i]<<"\n"; 
cout<<"COMPLETION TIME \n";
ct[0]=bt[0];
for(i=1;i<n;i++)
{
if(ct[i-1]>at[i])
{ int d;
d=getmin(i,n,p);
string k;
int t;
     t=at[i];
      at[i]=at[d];
      at[d]=t;
      k=pn[i];
      pn[i]=pn[d];
      pn[d]=k;
      t=bt[i];
      bt[i]=bt[d];
      bt[d]=t;
      t=p[i];
      p[i]=p[d];
      p[d]=t;
ct[i]=ct[i-1]+bt[i];
}
    else{
    ct[i]=ct[i-1]+bt[i];
}
}   cout<<"PROCESS NAME \t COMPLETION TIME \n";
   for(i=0;i<n;i++)
    cout<<"\t"<<pn[i]<<"\t\t"<<ct[i]<<"\n";
	    cout<<"TURN AROUND TIME \n";
    for(i=0;i<n;i++)
    {
     tt[i]=ct[i]-at[i];
     wt[i]=tt[i]-bt[i];
}
cout<<"PROCESS NAME \t ARIVAL TIME \t BURST TIME \tPRIORITY \t COMPLETION TIME \t TURN AROUND TIME     WAITING TIME \t \n";
for(i=0;i<n;i++)
{
cout<<"\t"<<pn[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<p[i]<<"\t\t"<<ct[i]<<"\t\t\t"<<tt[i]<<"\t\t"<<wt[i]<<"\n";
} 
return 0; 
}