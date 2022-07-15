#include<iostream>
using namespace std;
int main()
{
int i,j,k,l=0;
for (i=1;i<100;i++)
{
for(j=2;j<i;j++)
{
if(i%j==0)
 {k=0;
 break;
 }
else
 k=1;
 }
if(k==1)
 {cout<<i<<"::";
  l++;}
else
 cout<<"";
}
cout<<endl;
cout<<l;
return 0;
}

