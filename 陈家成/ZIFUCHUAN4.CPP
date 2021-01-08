#include<iostream>
using namespace std;

void main()
{
	int m,n;
	int i,j;
	char s[10][10];
	cin>>m>>n;//m为列，n为行
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>s[i][j];
		}
	}
	 int b,a;
	cin>>b;
	for(a=0;a<b;a++)//经历的病毒周期
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(s[i][j]=='X')
				{
					if(j-1>=0)
					{
						s[i][j-1]='Y';
					}
					if(j+1!='\0')
					{
						if(s[i][j+1]=='P'||s[i][j+1]=='X'){}//判读感染的下一个是否为P或者X   
						else{s[i][j+1]='Y';}
					}
					if(i-1>=0)
					{
						s[i-1][j]='Y';
					}
					if(i+1!='\0')
					{
						if(s[i][j+1]=='X')
						{}
							s[i+1][j]='Y';
						
					}
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(s[i][j]=='Y')//将所替换的Y全部换成X
				{
					s[i][j]='X';
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<s[i][j];
		}
		cout<<endl;
	}
}