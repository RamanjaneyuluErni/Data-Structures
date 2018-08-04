#include<iostream>
#include<queue>
using namespace std;
int no=1,cv;
void drawundiredge(int A[][20],int u,int v,int n)
{
	A[u][v]=1;A[v][u]=1;cout<<"Added edge from "<<u<<"<->"<<v<<"\n";
}
void printdft(int A[][20],int n,int u,int isv[],int number[],int low[],int parent[],int backedge[])
{
	isv[u]=1;number[u]=no++;
	for(int i=1;i<=n;i++)
	{
		if(A[u][i]==1)
		{
			if(isv[i]==0)
			{
				parent[i]=u;
				printdft(A,n,i,isv,number,low,parent,backedge);
			}
			else
			{
				if(backedge[u]>number[i]&&number[i]<number[u]&&parent[u]!=i&&u!=cv)backedge[u]=number[i];
			}
		}
	}
	int min=number[u];
				for(int j=1;j<=n;j++)
				{
					if(A[u][j]&&backedge[u]!=number[j]&&low[j]<min)min=low[j];
				}
				low[u]=min;
				if(backedge[u]!=999&&backedge[u]<low[u])low[u]=backedge[u];
}
void pabicom(int A[][20],int n,int number[],int parent[],int backedge[])
{
	int isv[20];
	for(int i=1;i<=n;i++)isv[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(backedge[i]!=999)
		{
			int k=backedge[i],j=i;
			while(number[j]!=k)
			{
				isv[j]=1;
				cout<<j<<"-"<<parent[j]<<" ";j=parent[j];
			}isv[j]=1;
			cout<<j<<"-"<<i<<" ";
			cout<<endl;
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(A[i][j]&&(isv[i]==0||isv[j]==0))
	{
		cout<<i<<"-"<<j<<endl;
		isv[i]=1;isv[j]=1;
	}
}
int main()
{
	int n,i,j;cout<<"enter no.of vertices: ";
	cin>>n;int A[n+1][20];
	for(i=1;i<=n;i++){for(j=1;j<=n;j++)A[i][j]=0;}
	cout<<"enter names of vertices to join(! to stop): ";
	while(1)
	{
		cin>>i;if(i==-1)break;cin>>j;
		drawundiredge(A,i,j,n);
	}
	cout<<"enter first vertex:\n";
	cin>>cv;
	int isv[20],number[20],low[20],parent[20],backedge[20];
	for(i=1;i<=n;i++){isv[i]=0;number[i]=0;low[i]=999;parent[i]=0;backedge[i]=999;}
	printdft(A,n,cv,isv,number,low,parent,backedge);
	pabicom(A,n,number,parent,backedge);
	return 0;
}
