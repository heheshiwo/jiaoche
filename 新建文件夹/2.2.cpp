#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct monkey
{
 int num;
 struct monkey *next;
} Monkey,*LINK;
void main()
{
 int n,m;
 cin>>n>>m;
 LINK p,head,p2;
 int i;
 head=p=p2=(LINK)malloc(sizeof(Monkey));
 for(i=1;i<n;i++){
 p=(LINK)malloc(sizeof(Monkey));
 p2->next=p;
 p2=p;
 }
 p2->next=head;
 p=head;
 printf("�Ժ��ӽ��б�ţ�\n");
 for(i=1;i<=n;i++){
 p->num=i;
 printf("%d�ź��ӣ�%d\n",p->num,p->num);
 p=p->next;
 }
 i=0;
 p=head;
 while(1){
 i++;
 printf("%d�ź��ӱ���%d\n",p->num,i);
 if(p->next==p)
 break;
 if(i==m)
{
 i=0;
 printf("%d�źﱻ��̭\n",p->num);
 printf("\n");
 p2->next=p->next;
 p=p2->next;
 continue;
}
 else
{
 if(i==m-1)
 p2=p;
 p=p->next;
}}
 printf("ʤ��:%d",p->num);
}