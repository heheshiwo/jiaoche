#include <iostream>
using namespace std;
int fun1(int a,int b)
{
int c,d,e,f,g;
if(a<100&&a>0&&b<100&&b>0)
	{
		d=a/10;
		e=b%10;
		f=a%10;
		g=b/10;
		c=1000*f+100*e+10*d+g;
		return(c);
	}
	else
	{
		printf("�����������������룡\n");
	}
}
int fun2(int &a,int &b,int &c)
{
int d,e,f,g;
if(a<100&&a>0&&b<100&&b>0)
	{
		d=a/10;
		e=b%10;
		f=a%10;
		g=b/10;
		c=1000*f+100*e+10*d+g;
	}
	else
	{
		printf("�����������������룡\n");
	}
	return 0;
}
int fun3(int *a,int *b,int *c)
{
int d,e,f,g;
if(*a<100&&*a>0&&*b<100&&*b>0)
	{
		d=*a/10;
		e=*b%10;
		f=*a%10;
		g=*b/10;
		*c=1000*f+100*e+10*d+g;
	}
	else
	{
		printf("�����������������룡\n");
	}
	return 0;
}
int main()
{
    int num1,num2,s1,s2,s3;
    cin>>num1;
	cin>>num2;
    s1=fun1(num1,num2);
    printf("fun1���ս��:%d\n",s1);
    fun2(num1,num2,s2);
    printf("fun2���ս��:%d\n",s2);
    fun3(&num1,&num2,&s3);
    printf("fun3���ս��:%d\n",s3);
    return 0;
}