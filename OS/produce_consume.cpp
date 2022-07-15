#include<iostream>
using namespace std;
void producer();
void consumer();
int wait(int);
int signal(int);
int mutex=1,empty=3,full=0,x=0;
int main()
{
	int ch;
	do
	{
		cout<<"\n main menu";
		cout<<"\n press 1 for producer";
		cout<<"\n press 2 for consumer";
		cout<<"\n press 3 for exit";
		cout<<"\n enter ur choice";
		cin>>ch;
		switch(ch)
		{
			case 1:if((mutex==1)&&(empty!=0))
					producer();
				   else
					cout<<"\n buffer is full";break;
			case 2:if((mutex==1)&&(full!=0))
					consumer();
					else
					cout<<"\n buffer is empty";
			case 3:break;
			default:cout<<"\n wrong choice";
		}
	}while(ch!=3);
}
void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(mutex);
	x++;
	cout<<"\n item produced is"<<x;
	mutex=signal(mutex);
}
void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(mutex);
	cout<<"\n item consumed  is"<<x;
	x--;
	mutex=signal(mutex)  ;
}
int wait(int s)
{
	return--s;
}
int signal(int s)
{
	 return ++s;
}
