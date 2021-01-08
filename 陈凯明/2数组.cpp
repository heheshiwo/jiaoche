#include<iostream>
#include<string>
using namespace std;

void main()
{
	int m,n,t,i,count=0;
	int a[1000];
	cout<<"输入猴子个数和N"<<endl;
	cin>>m>>n;
	cout<<m<<endl<<n<<endl;
	t=m;
	for(i=0;i<m;i++)
	{
		a[i]=1;
	}
	while(t!=1)
	{
		for(i=0;i<m;i++)
		{
			if(a[i]==1)
			{
				count++;
			}
			if(count==n)
			{
			a[i]=0;
			t--;
			count=0;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		if(a[i]==1)
		{
			cout<<i+1<<endl;
			break;
		}
	}
}

