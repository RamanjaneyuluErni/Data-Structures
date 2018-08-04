#include<iostream>
#include<queue>
using namespace std;
int b[20][20],n,count=0,edge=0,V[10];
void printqueue(queue<int>q)
{
	count++;
	while(q.size()!=0){cout<<q.front()<<" ";q.pop();}cout<<endl;
}
void printmatrix()
{
   cout<<"  ";
   for(int i=1;i<=n;i++) cout<<i<<" ";cout<<endl;
   for(int i=1;i<=n;i++)
	{
	   cout<<i<<" ";
	   for(int j=1;j<=n;j++) cout<<b[i][j]<<" ";cout<<endl;
    }
} 
int degree(int i)
{
	int c=0;for(int j=1;j<=n;j++){if(b[j][i]!=0)c++;}return c;
} 
void printpaths(int cv,int g,queue<int>q)
{
	q.push(cv);V[cv]=1;
	if(cv==g)
	{
		printqueue(q);return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[cv][i]!=0 && V[i]==0)
		{
			b[cv][i]=0;b[i][cv]=0;printpaths(i,g,q);
			b[cv][i]=1;b[i][cv]=1;V[i]=0;
		}
	}
}
int main()
{
	int i,j,k,v,u,g;char c1,c2;
	cout<<"no of vertices:";cin>>n;
	for(i=1;i<=n;i++) 	{ V[i]=0;for(j=1;j<=n;j++) b[i][j]=0; }
	cout<<"enter vertices to join(-1 to stop)\n";	
	while(1)
	{
		cin>>u;if(u==-1)break;cin>>v;
		b[u][v]=1;b[v][u]=1;edge++;
	}
    printmatrix();
    queue<int>q;
    cout<<"enter start vertex(from 1 to n):";cin>>v;
    cout<<"enter goal vertex:";cin>>g;
    printpaths(v,g,q);
    cout<<"\ntotal no of paths:"<<count;
    return 0;
}
