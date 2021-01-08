#include<iostream>
using namespace std;

int fun(int m,int n)
{
  int c;
  int ge,shi,bai,qian;
  qian=m%10;
  shi=m/10;
  ge=n/10;
  bai=n%10;
  c=ge+10*shi+100*bai+1000*qian;
  return c;

}
int main()
{
	int m,n,c;
	cin>>m>>n;
	c=fun(m,n);
	cout<<c;
	return 0;

}