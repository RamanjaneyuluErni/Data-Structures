#include<iostream>
#include<cstring>
using namespace std;
int b[20][20],n;char a[10];
void printmatrix()
{
   cout<<"  ";
   for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
   for(int i=0;i<n;i++)
	{
	   cout<<a[i]<<" ";
	   for(int j=0;j<n;j++) cout<<b[i][j]<<" ";cout<<endl;
    }
}
int addedge(char c1,char c2,int n)
{
	int v,u;
	for(v=0;v<n;v++) if(a[v]==c1) break;if(v==n) return n;
	for(u=0;u<n;u++) if(a[u]==c2) break;if(u==n) return n;
	b[v][u]=1;b[u][v]=1;
	return -1;
}
int degree(int i)
{
	int c=0;
	for(int j=0;j<n;j++)
	{
		if(b[j][i]!=0)c++;  
	}
	return c;
}
int maxdegree(int i)
{
	int max=0,t,f=0;
	for(int k=0;k<n;k++)
	{
		if(b[i][k]!=0 && degree(k)>max) 
		{
		   max=degree(k);t=k;f=1;
		}
	}
	if(f==0) return -1;
	return t;
}
int main()
{
	int i,j,k,v;char c1,c2;
	cout<<"no of vertices:";cin>>n;
	cout<<"enter vertices\n";
	for(i=0;i<n;i++) 
	{
		cin>>a[i];for(j=0;j<n;j++) b[i][j]=0;  
	}
	cout<<"enter vertices to join(# to stop)\n";	
	while(1)
	{
		cin>>c1;if(c1=='#') break;cin>>c2;
		if(addedge(c1,c2,n)==n) cout<<"vertex not found\n";
	}
 printmatrix();
 cout<<"enter initial vertex:";cin>>v;
 cout<<"final euler's path:"<<a[v]<<" ";
 int cv=v;
 while(1)
 {
   	 int m=maxdegree(cv);
	 if(m==-1)break;
	 b[cv][m]=0;b[m][cv]=0;
	 cout<<a[m]<<" ";cv=m;
 }
}
