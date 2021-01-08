#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct student
{
	int id;//学号
	int chinese;//语文
	int math;//数学
	int english;//英语
	int sum;//总分
}s[55];
int judge(struct student a, struct student b)//判断函数
{
	if(a.sum==b.sum)//如果总分相等 
	   { 
	       //按语文成绩高低排序 
		    if(a.chinese==b.chinese)
			return a.id<b.id; 
		    return a.chinese>b.chinese;
	   }
	   return a.sum>b.sum; 
}
int main()
{
	int m, i;
	cin>>m;//输入学生总数
	for(i = 0; i <m; i++)
	{
		s[i].id = i+1;
		cin>>s[i].chinese>>s[i].math>>s[i].english;
		s[i].sum = s[i].chinese+s[i].math+s[i].english;//成绩总分
	}
	sort(s, s+m, judge);//排序总分
	for(i = 0; i <5; i++)//输出前五个学生的成绩
	{
		cout<<s[i].id<<' '<<s[i].sum<<endl;
	}
	return 0;
}