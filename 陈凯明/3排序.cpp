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
		return x.sum>y.sum;//��sumֵ�Ӹߵ�������
	}
	else
	{
		if(x.ch!=y.ch)
		{
			return x.ch>y.ch;//��chֵ�Ӹߵ�������
		}
		else
		{
			return x.id<y.id;//��idֵ��С��������
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
	sort(stu,stu+n,compare);//sort����������ͷ�ļ�Ϊ#include<algorithm>��c++��׼���У����ñ�׼��������򷽷�����ʵ�ֶ����ݵ�����
	for(i=0;i<5;i++)
	{
		cout<<stu[i].id<<" "<<stu[i].sum<<endl;
	}
}


