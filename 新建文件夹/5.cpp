#include<iostream>
#include<stack>
#include<string>
using namespace std;

int count(char z,int x,int y)
{
	switch(z)
	{
	case '+': return x+y;
	case '-': return x-y;
	case '*': return x*y;
	default : return 0;
	}
}
void main()
{
	char a[100];
	int k[10][1];
	stack<char> s;
	stack<int> num;
	stack<char> r;
	int n=0,m=0,i; 
	int check1=1;
	int check2=0;
	int z;
	cout<<"ÊäÈëËãÊ½"<<endl;
	gets(a);
    int log=strlen(a);
	for(i=0;i<log;i++)
	{
		if(a[i]==40)
		{   
			m++;
			s.push(m);
			check1=1;
			k[m-1][0]=n;
			n=0;
			//cout<<"¼ì²âµ½×óÀ¨ºÅ"<<endl;
		}
		else if(a[i]==41)
		{  
				s.pop();  
				check2=1;	
				//cout<<"¼ì²âµ½ÓÒÀ¨ºÅ"<<endl;
			while(n)
			{
				int bnow=num.top();  
				num.pop();
				int anow=num.top();
				num.pop();
				char ing=r.top();
				r.pop();
				int nowc=count(ing,anow,bnow);
				num.push(nowc);
				n--;
			}
			//cout<<num.top()<<endl;
			m--;
			n=k[m][0];
			check2=0;
			check1=1;
		}
		else if((a[i]>=48 && a[i]<=57) && (a[i-1]>=48 && a[i-1]<=57))
		{
			switch(a[i])
			{
			case 48: z=0;break;
			case 49: z=1;break;
			case 50: z=2;break;
			case 51: z=3;break;
			case 52: z=4;break;
			case 53: z=5;break;
			case 54: z=6;break;
			case 55: z=7;break;
			case 56: z=8;break;
			case 57: z=9;break;
			}			
			int nnum=num.top()*10+z;
			num.pop();
			num.push(nnum);
		}
		else if(a[i]>=48 && a[i]<=57)
		{
			switch(a[i])
			{
			case 48: z=0;break;
			case 49: z=1;break;
			case 50: z=2;break;
			case 51: z=3;break;
			case 52: z=4;break;
			case 53: z=5;break;
			case 54: z=6;break;
			case 55: z=7;break;
			case 56: z=8;break;
			case 57: z=9;break;
			}
			num.push(z);
			//cout<<z<<endl;
		}
		else if((check1==1)&&(a[i]<48))		
		{
			r.push(a[i]);
			check1=0;
			n++;
			//cout<<a[i]<<endl;
		}
		else if((a[i]=='+'||a[i]=='-'||a[i]=='*')&&(r.top()=='*'))
		{
			//cout<<a[i]<<endl;
			if(check1==0)
			{
				//cout<<"check1=0"<<endl;
				int bnow=num.top();  
				num.pop();
				int anow=num.top();
				num.pop();
				char ing=r.top();
				r.pop();
				int nowc=count(ing,anow,bnow);
				num.push(nowc);
				r.push(a[i]); //ĞÂÔËËã·û½øÕ»
				//cout<<num.top()<<endl;
			}
			else
			{
				//cout<<"check1=1"<<endl;
				r.push(a[i]);
				check1=0;
				n++;}}
		else if((a[i]=='+'||a[i]=='-')&&(r.top()=='+'||r.top()=='-'))
		{
			//cout<<a[i]<<endl;
			if(check1==0)
			{
				//cout<<"check=0"<<endl;
				int bnow=num.top();  
				num.pop();
				int anow=num.top();
				num.pop();
				char ing=r.top();
				r.pop();
				int nowc=count(ing,anow,bnow);
				num.push(nowc);
				r.push(a[i]); 
				//cout<<num.top()<<endl;
			}
			else
			{
				//cout<<"check1=1"<<endl;
				r.push(a[i]);
				check1=0;
				n++;
			}}
		else if((a[i]=='*')&&(r.top()=='+'||r.top()=='-'))
		{
			//cout<<a[i]<<endl;
			r.push(a[i]);
			check1=0;
			n++;}
		else if(a[i]=='=')
		{	
			//cout<<"n="<<n<<endl;
			while(n)
			{
				int bnow=num.top();  
				num.pop();
				int anow=num.top();
				num.pop();
				char ing=r.top();
				r.pop();
				int nowc=count(ing,anow,bnow);
				z=nowc;
				num.push(nowc);
				n--;
			}}}
	cout<<z<<endl;;   }