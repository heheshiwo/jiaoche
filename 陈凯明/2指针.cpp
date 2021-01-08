#include<iostream>
#include<string>
using namespace std;

struct line
{
    int data;
    line *next;
};
 
void main()
{
    int m,n,i;
	cout<<"输入猴子数量和N"<<endl;
    while(cin>>m>>n&&m)
	{
		line *a;
		line *p,*q;
		a = new line;
		a->data = 1;
		a->next = a;
		if(n!=1)
		{
			for(i=m;i>=2;i--)
			{
				p=new line;
				p->data = i;
				p->next=a->next;
				a->next=p;
			}
			q = a;
			while(q->next!=q)
			{
				m=n-2;
				while(m--)
				{
					q=q->next;
				}
				p=q->next;
				q->next=p->next;
				delete p;
				q=q->next;
			}
			cout<<q->data<<endl;
		}
		else
			cout<<n<<endl;
		while(a->next!=a)
		{
			q=a;
			a=a->next;
			delete q;
		}
		delete a;
	}
}
