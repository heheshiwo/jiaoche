#include<iostream>
using namespace std;

//struct space{
//	int id;
//}sc[15][15];

void main(){
	char a[10][10];
	char sc[10][10];
	int i,j,k;
	int n,m;
	int c;
	cin>>n>>m;
	cin>>c;
	for(i=0;i<n;i++){ 
	for(j=0;j<m;j++){
	cin>>a[i][j];
	sc[i][j]=a[i][j];
		}}
	for(k=0;k<c;k++){
	for(i=0;i<n;i++){
	for(j=0;j<m;j++){
	if(a[i][j]=='x'){     
	if(sc[i][j]!='p')      sc[i][j]='x';
	if(sc[i][j+1]!='p'&&j+1>=0) sc[i][j+1]='x';
	if(sc[i+1][j]!='p'&&i+1>=0) sc[i+1][j]='x';
	if(sc[i-1][j]!='p'&&i-1>=0) sc[i-1][j]='x';
	if(sc[i][j-1]!='p'&&j-1>=0) sc[i][j-1]='x';
				}}}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				a[i][j]=sc[i][j];   
			}}}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}}