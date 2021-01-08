#include<iostream>
#include<cstring>
using namespace std;
#include<cstdio>
    struct node{
    int yuwen,shuxue,waiyu,zongfen;
    int id;
    };
    node student[330];
int main()
{
    int n,i,j;

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>student[i].yuwen>>student[i].shuxue>>student[i].waiyu;
        student[i].id=i;
        student[i].zongfen=student[i].shuxue+student[i].yuwen+student[i].waiyu;
    }

    for(i=n-1;i>=1;i--)
        for(j=1;j<=i;j++)//条件需要写清楚，这里很容易出错，冒泡法排序的起点和终点需要明确，遍历很容易超出范围
        {    if(student[j].zongfen<student[j+1].zongfen)            
            swap(student[j],student[j+1]);
            else if((student[j].zongfen==student[j+1].zongfen)&&(student[j].yuwen<student[j+1].yuwen))
              swap(student[j],student[j+1]);    
            else if((student[j].zongfen==student[j+1].zongfen)&&(student[j].yuwen==student[j+1].yuwen)&&student[j].id>student[j+1].id)
                swap(student[j],student[j+1]);
        }    
    for(i=1;i<=5;i++)
        cout<<student[i].id<<" "<<student[i].zongfen<<endl;
        return 0;
}