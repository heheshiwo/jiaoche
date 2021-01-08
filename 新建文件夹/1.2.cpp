#include<iostream>
using namespace std;

void fun(int &m,int &n,int &c)
{
  int ge,shi,bai,qian;
  qian=m%10;
  shi=m/10;
  ge=n/10;
  bai=n%10;
  c=ge+10*shi+100*bai+1000*qian;
}

int main()
{
	int m,n,c=0;
	cin>>m>>n;
	fun(m,n,c);
	cout<<c;
	return 0;

}