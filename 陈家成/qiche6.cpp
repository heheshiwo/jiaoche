#include<iostream>
#include <math.h>
using namespace std;

class vehicle // ����������
{
protected:
int wheels; // ������
float weight; // ����
public:
vehicle(int cl, int zl)
{
wheels=cl;
weight=zl;
}
void shuchu()//�������ͳ��ص����
{
cout <<"��������"<<wheels <<"���أ�"<<weight<<endl;
}
};

class car:private vehicle//С����car
{
int passenger_load;
public:
car(int cl,int zl,int rs) :vehicle(cl,zl)
{
passenger_load=rs;
}
void shuchu()
{
vehicle::shuchu();//С����car�����
cout << "С����������"<<passenger_load<<endl;
}
};

class truck :private vehicle//������truck
{
int passenger_load;
int payload;
public:
truck(int cl,int zl,int rs,int zzl):vehicle(cl,zl)
{
passenger_load=rs;
payload=zzl;
}
void shuchu()//������truck�����
{
vehicle::shuchu();
cout<<"������������"<<passenger_load <<"��������"<<payload<<endl;
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
