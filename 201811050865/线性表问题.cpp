#include<iostream>
#include <stdio.h> 
using namespace std;
void MonkeyKing(int m,int n)                          
{
	int i=0;
	int *Monkey=new int[m];
	for(i=0;i<m;i++)
	{
		Monkey[i]=1;
	}
	int k=0;
	int j=m;
	while(j!=1)
	{
		for(i=0;i<m;i++)
		{
			k=k+Monkey[i];
			if(k==n)
			{
				Monkey[i]=0;
				k=0;
				j--;
			}
		}
	}   
	for(i=0;i<m;i++)
	{
		if(Monkey[i]==1)
		{
			cout<<"Monkey King is No."<<i+1;
		}
	}
	delete []Monkey;
}

int main()
{
	int m,n;
	cout<<"输入猴子的个数:";
	cin>>m;
	cout<<"输入报的数字:";
	cin>>n;
	if(m<n)
	{
		cout<<"输入错误";
	}
    MonkeyKing(m,n);

	return 0;

}

/*struct node{
	int data;
	int last;
	int next;
};
 
struct node a[1100];
 
int main(int argc, char** argv) 
{
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=2;i<n;i++)
		{
			a[i].data=i;  a[i].last=i-1;  a[i].next=i+1;
		}
		a[1].data=1; a[1].last=n;   a[1].next=2;
		a[n].data=n; a[n].last=n-1; a[n].next=1;
		
		int num=1;       //记录报数次数 
		int count=1;     //记录当前猴子的序号 
		while(a[count].next!=a[count].data)
		{
			if(num%3==0)
			{
				a[a[count].last].next=a[count].next;
				a[a[count].next].last=a[count].last;
				
			}
			num++;
			count=a[count].next;
		}
		printf("%d\n",a[count].data);
	}
	
	return 0;
}*/


