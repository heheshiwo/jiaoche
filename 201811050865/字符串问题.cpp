#include<iostream>
using namespace std;

void main()
{
	int m,n;
	int i,j;
	char t[10][10];
	cin>>m>>n;//m为行，n为列
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>t[i][j];
		}
	}
	 int c,a;
	cin>>c;
	for(a=0;a<c;a++)
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(t[i][j]=='X')
				{
					if(j-1>=0)
					{
						t[i][j-1]='Y';
					}
					if(j+1!='\0')
					{
						if(t[i][j+1]=='P'||t[i][j+1]=='X'){}
						else{t[i][j+1]='Y';}
					}
					if(i-1>=0)
					{
						t[i-1][j]='Y';
					}
					if(i+1!='\0')
					{
						if(t[i][j+1]=='X')
						{}
							t[i+1][j]='Y';
						
					}
				}
			}
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(t[i][j]=='Y')
				{
					t[i][j]='X';
				}
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<t[i][j];
		}
		cout<<endl;
	}

}

