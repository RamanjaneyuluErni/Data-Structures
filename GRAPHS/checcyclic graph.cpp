#include<iostream>
using namespace std;
int n,b[10][10];
int find(int a[],int i)
{
	if(a[i]==0)return i;
	return find(a,a[i]);
}
void createset(int a[],int i,int j)
{
	if(a[i]==0)a[i]=j;
	else if(a[j]==0)a[j]=i;
	else
	{
		if(a[find(a,i)]==0) a[find(a,i)]=j;
		else if(a[find(a,j)]==0) a[find(a,j)]=i;
	}
}
void printmatrix(int v[])
{
   cout<<"  ";
   for(int i=1;i<=n;i++) cout<<v[i]<<" ";cout<<endl;
   for(int i=1;i<=n;i++)
	{
	   cout<<v[i]<<" ";
	   for(int j=1;j<=n;j++) cout<<b[i][j]<<" ";cout<<endl;
    }
} 
int main()
{
	int i,j;int f=0; 
	cout<<"enter no of vertices:";cin>>n; int a[n+1];char v[n];
	cout<<"enter vertices\n";
	for(i=1;i<=n;i++) 
	{
		cin>>v[i];a[i]=0;for(j=1;j<=n;j++) b[i][j]=0;
	}
	while(1)
	{
		cout<<"enter vertices graph(-1,-1 to stop)\n";
		cin>>i>>j;
		if(i==-1&&j==-1)break;
		b[i][j]=1;b[j][i]=1;
		if(find(a,i)!=find(a,j))createset(a,i,j);
		else f=1;
	}
	if(f==1) cout<<"cyclic graph\n";
	else cout<<"acyclic graph\n";
	return 0;
}
