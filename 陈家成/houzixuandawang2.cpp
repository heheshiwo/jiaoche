#include <iostream>
#include <stdio.h> 
using namespace std;
typedef struct monkey 
{
    int num;
    struct monkey * next;
} monkey_t;
//headָ���һ���ڵ㣬tailָ�����һ���ڵ�
monkey_t *head = NULL, *tail = NULL;
 
void create(int nn) {   //���ӵĸ���
    int i;
    monkey_t *p = NULL, *q = NULL;//pָ��һ���·���Ľڵ㣬qָ��ǰ���һ���ڵ�
    p = (monkey_t *)malloc(sizeof (monkey_t));
    p->num = 1;
    p->next = NULL;
    head = p;
    q = p;
    for (i = 2; i <= nn; i++)
	{
        p = (monkey_t *)malloc(sizeof (monkey_t));
        p->num = i;
        p->next = NULL;
        q->next = p;
        q = p;
    }
    tail = q;
    tail->next = head;  //�γɱջ�
}
 
int select(int mm) 
{
    int x = 0, res;
    monkey_t *p = NULL, *q = NULL;  //pָ��ǰҪ�жϵĽڵ㣬q������p�ĺ��棬��p��һ��
    q = tail;
    do 
	{
        p = q->next;    //��λp
        x++;
        if (x % mm == 0) 
		{
            q->next = p->next;
            free(p);
            //p = NULL;
        } else {
            q = p;  //q����һ��
        }
    } while (q != q->next); //ѭ��ֱ��ֻʣ��һ���ڵ�
    //head = q;
    res = q->num;
    free(q);
    return res;
}
 
void main() 
{
    int n, m;
    cout<<"�����������������̭����";
    cin>>m>>n;  
    create(m);
    cout<<"��"<<select(n)<<"������Ϊ����"<<endl;
}
