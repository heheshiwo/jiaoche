#include<iostream>
#include<string>
using namespace std;

int fun1(int a,int b)
{
	int m,n,t,e;
	int c=0,d=0,f=0,h=0,i=0;
	m=a/10;//a��ʮλ������
	n=a%10;//a�ĸ�λ������
	t=b/10;//b��ʮλ������
	e=b%10;//b�ĸ�λ������
	c=1000*n+100*e+10*m+t;
	return c;
}
void fun2(int &a,int &b)
{
	int m,n,t,e;
	m=a/10;//a��ʮλ������
	n=a%10;//a�ĸ�λ������
	t=b/10;//b��ʮλ������
	e=b%10;//b�ĸ�λ������
	a=1000*n+10*m;
	b=100*e+t;
}
void fun3(int *p,int *q)
{
    int m,n,t,e;
	m=*p/10;//a��ʮλ������
	n=*p%10;//a�ĸ�λ������
	t=*q/10;//b��ʮλ������
	e=*q%10;//b�ĸ�λ������
	*p=1000*n+10*m;
	*q=100*e+t;
}
void main()
{
	int a,b,c=0,d=0,e=0;
	printf("������������λ��:");
	scanf("%d,%d",&a,&b);
	d=a;e=b;
	c=fun1(a,b);
	printf("�ϲ�������Ϊ\n");
	printf("%d\n",c);
	fun2(a,b);
	c=a+b;
	printf("���ò�����\n");
	printf("%d\n",c);
	a=d;b=e;
	fun3(&a,&b);
	c=a+b;
	printf("ָ�������\n");
	printf("%d\n",c);
}

