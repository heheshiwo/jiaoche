#include<iostream>
using namespace std;
int main()
{
	int m,n,number,count=1;		
	int monkey[999];
	int f;						
	int i;
	cin>>m>>n;
	number = m;
	for(i=0;i<m;i++)
		monkey[i]=i+1;
	f=0;
	while(number>1)
	{
		if(monkey[f]>0)
		{
			if(count!=n)
			{
				cout<<"����"<<f+1<<"��"<<count<<endl;
				count++;
				f=(f+1)%m;		
			}
			else
			{
				monkey[f]=0;
				cout<<"����"<<f+1<<"��"<<count<<endl;
				count=1;
				number--;
				f=(f+1)%m;
			}
		}
		else
		{
			f=(f+1)%m;
		}
	}
	for(i=0;i<m;i++)
	{
		if(monkey[i]>0)
        cout<<"���Ӵ���"<<monkey[i]<<endl;
	}
	return 0;
}