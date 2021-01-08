#include<iostream>
#include <math.h>
using namespace std;

class vehicle // 定义汽车类
{
protected:
int wheels; // 车轮数
float weight; // 重量
public:
vehicle(int cl, int zl)
{
wheels=cl;
weight=zl;
}
void shuchu()//车轮数和车重的输出
{
cout <<"车轮数："<<wheels <<"车重："<<weight<<endl;
}
};

class car:private vehicle//小车类car
{
int passenger_load;
public:
car(int cl,int zl,int rs) :vehicle(cl,zl)
{
passenger_load=rs;
}
void shuchu()
{
vehicle::shuchu();//小车类car的输出
cout << "小车载人数："<<passenger_load<<endl;
}
};

class truck :private vehicle//卡车类truck
{
int passenger_load;
int payload;
public:
truck(int cl,int zl,int rs,int zzl):vehicle(cl,zl)
{
passenger_load=rs;
payload=zzl;
}
void shuchu()//卡车类truck的输出
{
vehicle::shuchu();
cout<<"卡车载人数："<<passenger_load <<"载重量："<<payload<<endl;
}
};

void main()
{
vehicle c(10, 9);
c.shuchu();
car a(4, 8, 5);
a.shuchu();
truck k(24, 15, 4, 12);
k.shuchu();
};
