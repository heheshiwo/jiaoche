#include<iostream>
using namespace std;
int fun1()
{
	int a,b,c,d,e,f,g;
	cout<<"请输入两个两位数的正整数"<<endl;
	cin>>a>>b;
    if(a<100&&a>0&&b<100&&b>0)
	{
		d=a/10,e=b%10,f=a%10,g=b/10;
		c=1000*d+100*e+10*f+g;
		cout<<c<<endl;
	}
	else
	{
		cout<<"输入错误"<<endl;
	}
	return c;
}
void fun2(int a,int b,int c)
{
	int d,e,f,g;
	cout<<"请输入两个两位数的正整数"<<endl;
	cin>>a>>b;
    if(a<100&&a>0&&b<100&&b>0)
	{
		d=a/10,e=b%10,f=a%10,g=b/10;
		c=1000*d+100*e+10*f+g;
		cout<<c<<endl;
	}
	else
	{
		cout<<"输入错误"<<endl;
	}
}
void fun3(int *p,int *q)
{
	int c,d,e,f,g;
    if(*p<100&&*p>0&&*q<100&&*q>0)
	{
		d=*p/10,e=*q%10,f=*p%10,g=*q/10;
		c=1000*d+100*e+10*f+g;
		cout<<c<<endl;
	}
	else
	{
		cout<<"输入错误"<<endl;
	}
}
void main()
{
	int a,b;
	cout<<"请输入两个两位数的正整数"<<endl;
	cin>>a>>b;
    fun3(&a,&b);

}

	

	


