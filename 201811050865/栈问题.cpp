#include<iostream>
#include<string>
using namespace std;
template<typename T>
class Node{
public:
	T element;
	Node *next;	
	Node(T element){
		this->element = element;
		next = NULL;
	}
};
//ջ��
template<typename T>
class Stack{
private:
	Node<T> *top;
	int size;
public:	
	Stack(){
		
		Node<T> *newNode = new Node<T>(0);
		top = newNode;
		size = 0;		
	}	
	int stackLength(){
		return size;
	}	
	bool stackEmpty(){
		if(0==size)
			return true;
		else
			return false;
	}	
	void Push(T e){
		Node<T> *newNode = new Node<T>(e);
		newNode->next = top->next;
		top->next = newNode;
		size++;
	}
	T Pop(){
		Node<T> *current = top->next;
		top->next = current->next;
		T f=current->element;
		delete current;
		size--;
		return f;
	}	
	T getTop(){
		return top->next->element;
	}
};
char Priority(char ch1,char ch2){
	int a;
	int b;
	switch(ch1){
	case '=' : a=0;
		break;
	case '(' : a= 1;
		break;
	case '+' : a= 3;
		break;
	case '-' : a= 3;
		break;
	case '*' : a= 5;
		break;
	case '/' : a= 5;
		break;
	case '%' : a= 5;
		break;
	case '^' : a= 7;
		break;
	case ')' : a= 8;
		break;
	}
	switch(ch2){
	case '=' : b=0;
		break;
	case '(' : b= 8;
		break;
	case '+' : b= 2;
		break;
	case '-' : b= 2;
		break;
	case '*' : b= 4;
		break;
	case '/' : b= 4;
		break;
	case '%': b= 4;
		break;
	case '^' : b= 6;
		break;
	case ')' : b= 1;
		break;
	}
	if(a<b)
		return '<';
	else if(a==b)
		return '=';
	else
		return '>';
}
int Compute(int a,int b,char sign){
	int result;
	switch(sign){
	case '+' : result=a+b;
		break;
	case '-' : result=a-b;
		break;
	case '*' : result=a*b;
		break;
	case '/' : result=a/b;
		break;
	case '%' : result=a%b;
		break;
	case '^' : result=a^b;
		break;
	}
	return result;	
}
int main()
{
	Stack<int> number;
	Stack<char> character;
	character.Push('=');
	cout<<"�������ʽ"<<endl;
	string s;
	getline(cin,s);
	string k="000000000000000000000000000000000000";	
	int sum=0;
	int i=0;
	int j=0;	
	while(s[i]!='=')
	{		
		if(s[i]>=48&&s[i]<=57)
		{
			sum=sum*10+(s[i]-48);			
			k[j]=sum;			
			i++;			
			if(s[i]<48||s[i]>57)
				j++;
		}
		else
		{
			sum=0;
			k[j]=s[i];
			j++;
			i++;
		}		
	}
	k[j]='=';	
	int kk=0;	
	int ch=k[kk++];
	char b;
	b=static_cast<char>(ch);
	while(b!='=' || character.getTop()!='='){
		if(ch=='+'||ch=='='||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')')
		{
			switch( Priority( character.getTop(), b)){
			case'<'://ջ��Ԫ�����ȼ���
				character.Push(b);
				ch = k[kk++];
				b=static_cast<char>(ch);
				break;
			case'=':
				character.Pop();
				ch = k[kk++];
				b=static_cast<char>(ch);
				break;
			case'>':
				number.Push(Compute(number.Pop(),number.Pop(),character.Pop()));				
				break;
			}
			
		}
		else{
			number.Push(ch);
			ch =k[kk++];
			b=static_cast<char>(ch);
		}
	}
	cout<<"����"<<" "<<number.getTop()<<'\n';
	
	return 0;
}  