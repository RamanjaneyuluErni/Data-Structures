#include<iostream>
#include<queue>
using namespace std;
int no=1;
void drawdiredge(int A[][20],int u,int v,int n)
{
	A[u][v]=1;cout<<"Added edge from "<<u<<"->"<<v<<"\n";
}
void reverse(int A[][20],int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i>j)
			{
				int temp=A[i][j];A[i][j]=A[j][i];A[j][i]=temp;
			}
		}
	}
}
void print(int A[][20],int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
		cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
void printdft(int A[][20],int n,int u,int isv[],int number[])
{
	isv[u]=1;
	for(int i=1;i<=n;i++)
	{
		if(A[u][i]==1&&isv[i]==0)
		{
			printdft(A,n,i,isv,number);break;
		}
	}
	number[u]=no++;
}
void dft(int A[][20],int n,int u,int isv[])
{
	isv[u]=1;cout<<u<<" ";
	for(int i=1;i<=n;i++)
	{
		if(A[u][i]==1&&isv[i]==0)
		{
			dft(A,n,i,isv);break;
		}
	}
}
int main()
{
	int n,i,j;cout<<"enter no.of vertices: ";char ch;
	cin>>n;int A[n+1][20];
	cout<<"enter names of the vertices: ";
	for(i=1;i<=n;i++){for(j=1;j<=n;j++)A[i][j]=0;}
	cout<<"enter names of vertices to join(! to stop): ";
	while(1)
	{
		cin>>i;if(i==-1)break;cin>>j;
		drawdiredge(A,i,j,n);
	}
	int isv[20],number[20];
	for(i=1;i<=n;i++){isv[i]=0;number[i]=0;}
	int u,v;
	while(1)
	{
		int f=0;for(i=1;i<=n;i++)if(isv[i]==0){f=1;break;}if(f==0)break;
		printdft(A,n,i,isv,number);
	}
	reverse(A,n);for(i=1;i<=n;i++)isv[i]=0;
	while(1)
	{
		int max=-1;
		for(i=1;i<=n;i++)
		{
			if(number[i]>max&&isv[i]==0){max=number[i];u=i;}
		}
		if(max==-1)break;
		dft(A,n,u,isv);cout<<endl;
		number[u]=-1;
	}
	
	return 0;
}
