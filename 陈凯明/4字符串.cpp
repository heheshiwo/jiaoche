#include<iostream>
#include<string>
using namespace std;

void main()
{
	int n,m,i,j,c,a;
	char p[100][100];
	cin>>n>>m;//���볤��n���m
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>p[i][j];
		}
	}
	cin>>c;
	for(a=0;a<c;a++)//ѭ�����X�����б任
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(p[i][j]=='X')
				{
					if(j-1>=0)
					{
						p[i][j-1]='Y';
					}
					if(j+1!='\0')
					{
						if(p[i][j+1]=='P'||p[i][j+1]=='X'){}
						else{p[i][j+1]='Y';}
					}
					if(i-1>=0)
					{
						p[i-1][j]='Y';
					}
					if(i+1!='\0')
					{
						if(p[i+1][j]=='X'){}
						p[i+1][j]='Y';
					}
				}
			}
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(p[i][j]=='Y')
				{
					p[i][j]='X';
				}
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<p[i][j];
		}
		cout<<endl;
	}
}





