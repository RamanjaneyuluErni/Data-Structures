#include<iostream>
using namespace std;
int b[10][10],V[10];char a[10];
void printDFT(int v,int n,int p[],int m)
{
	if(m==n)
	{
		for(int k=0;k<=m;k++) cout<<a[p[k]]<<" ";
		 cout<<endl;return;
	}
	for(int i=0;i<n;i++)
	   {
		  if(b[v][i]!=0 && V[i]!=1) 
		  {
		  	p[m]=i;V[i]=1;
		  	printDFT(i,n,p,m+1); 
		  	V[i]=0;
		  }
	   }
	   	
}
void addedge(char c1,char c2,int n)
{
	int v,u;
	for(v=0;v<n;v++) if(a[v]==c1) break;if(v==n) return;
	for(u=0;u<n;u++) if(a[u]==c2) break;if(u==n) return;
	b[v][u]=1;b[u][v]=1;
	cout<<"edge added b/w "<<a[v]<<" and "<<a[u]<<endl;
}
int main()
{
	char c,c1,c2;int n;
	cout<<"enter no of vertices:";cin>>n;
	cout<<"enter vertices:";
	for(int i=0;i<n;i++) 
	{ 
	      cin>>a[i];V[i]=0;
		  for(int j=0;j<n;j++) b[i][j]=0;
	} 
	while(1)
	{
		cout<<"enter vertices to join(# to stop)\n";
		cin>>c1;if(c1=='#') break;cin>>c2;
		addedge(c1,c2,n);
	}
    cout<<"  ";
   for(int i=0;i<n;i++) 
	  cout<<a[i]<<" ";cout<<endl;
   for(int i=0;i<n;i++)
	{
	   cout<<a[i]<<" ";
	  for(int j=0;j<n;j++)
	  {
	  	cout<<b[i][j]<<" ";
	  }cout<<endl;
    }
   int v,p[10],i=1;
   cout<<"enter initial vertex:";cin>>v; 
   p[0]=v;V[v]=1;
   printDFT(v,n,p,i); 
   return 0;
} 

