#include<iostream>
#include<algorithm>
using namespace std;

struct Stu
{
	int id;
	int ch;
	int m;
	int e;
	int sum;
}stu[200];
bool compare(Stu x,Stu y)
{
	if(x.sum!=y.sum)
	{
		return x.sum>y.sum;//按sum值从高到低排序
	}
	else
	{
		if(x.ch!=y.ch)
		{
			return x.ch>y.ch;//按ch值从高到低排序
		}
		else
		{
			return x.id<y.id;//按id值从小到大排序
		}
	}
}
void main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		stu[i].id=i+1;
		cin>>stu[i].ch>>stu[i].m>>stu[i].e;
		stu[i].sum=stu[i].ch+stu[i].m+stu[i].e;
	}
	sort(stu,stu+n,compare);//sort函数包含在头文件为#include<algorithm>的c++标准库中，调用标准库里的排序方法可以实现对数据的排序
	for(i=0;i<5;i++)
	{
		cout<<stu[i].id<<" "<<stu[i].sum<<endl;
	}
}


