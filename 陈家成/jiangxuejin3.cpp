#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct student
{
	int id;//ѧ��
	int chinese;//����
	int math;//��ѧ
	int english;//Ӣ��
	int sum;//�ܷ�
}s[55];
int judge(struct student a, struct student b)//�жϺ���
{
	if(a.sum==b.sum)//����ܷ���� 
	   { 
	       //�����ĳɼ��ߵ����� 
		    if(a.chinese==b.chinese)
			return a.id<b.id; 
		    return a.chinese>b.chinese;
	   }
	   return a.sum>b.sum; 
}
int main()
{
	int m, i;
	cin>>m;//����ѧ������
	for(i = 0; i <m; i++)
	{
		s[i].id = i+1;
		cin>>s[i].chinese>>s[i].math>>s[i].english;
		s[i].sum = s[i].chinese+s[i].math+s[i].english;//�ɼ��ܷ�
	}
	sort(s, s+m, judge);//�����ܷ�
	for(i = 0; i <5; i++)//���ǰ���ѧ���ĳɼ�
	{
		cout<<s[i].id<<' '<<s[i].sum<<endl;
	}
	return 0;
}