#include<iostream>
#include<string>
using namespace std;

int fun1(int a,int b)
{
	int m,n,t,e;
	int c=0,d=0,f=0,h=0,i=0;
	m=a/10;//a的十位的数字
	n=a%10;//a的个位的数字
	t=b/10;//b的十位的数字
	e=b%10;//b的个位的数字
	c=1000*n+100*e+10*m+t;
	return c;
}
void fun2(int &a,int &b)
{
	int m,n,t,e;
	m=a/10;//a的十位的数字
	n=a%10;//a的个位的数字
	t=b/10;//b的十位的数字
	e=b%10;//b的个位的数字
	a=1000*n+10*m;
	b=100*e+t;
}
void fun3(int *p,int *q)
{
    int m,n,t,e;
	m=*p/10;//a的十位的数字
	n=*p%10;//a的个位的数字
	t=*q/10;//b的十位的数字
	e=*q%10;//b的个位的数字
	*p=1000*n+10*m;
	*q=100*e+t;
}
void main()
{
	int a,b,c=0,d=0,e=0;
	printf("请输入两个两位数:");
	scanf("%d,%d",&a,&b);
	d=a;e=b;
	c=fun1(a,b);
	printf("合并后新数为\n");
	printf("%d\n",c);
	fun2(a,b);
	c=a+b;
	printf("引用参数法\n");
	printf("%d\n",c);
	a=d;b=e;
	fun3(&a,&b);
	c=a+b;
	printf("指针参数法\n");
	printf("%d\n",c);
}

