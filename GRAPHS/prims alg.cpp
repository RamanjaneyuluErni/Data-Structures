#include<iostream>
#include<cstring>
using namespace std;
char a[10];int b[10][10],V[10],n,adj[10],D[10];
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
int addedge(char c1,char c2,int n,int wt)
{
	int v,u;
	for(v=0;v<n;v++) if(a[v]==c1) break;if(v==n) return n;
	for(u=0;u<n;u++) if(a[u]==c2) break;if(u==n) return n;
	b[v][u]=wt;b[u][v]=wt;
	cout<<"edge added b/w "<<a[v]<<" and "<<a[u]<<endl;
	return -1;
}
int main()
{
	int wt,i,j,k,len=0,c,l,t,s;char c1,c2;
	cout<<"no of vertices:";cin>>n;
	cout<<"enter vertices\n";
	for(i=0;i<n;i++) 
	{
	   cin>>a[i];adj[i]=-1;V[i]=0;D[i]=-1;for(j=0;j<n;j++) b[i][j]=0; 	
	}
    while(1)
	{
		cout<<"enter vertices to join(# to stop)\n";
		cin>>c1;if(c1=='#') break;cin>>c2;
		cout<<"enter weight:";cin>>wt;
		if(addedge(c1,c2,n,wt)==n) cout<<"vertex not found\n";
	}
	printmatrix();
    cout<<"\nenter start vetex:\n";cin>>s;
    V[s]=1;
    while(1)
    {
    	c=0;
    	for(k=0;k<n;k++) 
		{
			if(V[k]==1) c++;
		}
		if(c==n) break;int min=999;
		for(i=0;i<n;i++)
		{
			if(V[i]==1)
			{
				for(j=0;j<n;j++)
				{
					if(b[i][j]!=0 && V[j]==0 && b[i][j]<min)
					{
						min=b[i][j];l=i;t=j;
					}
				}
			}
		}
		len=len+b[l][t];adj[t]=l;V[t]=1;D[t]=b[l][t];
	}
	for(i=0;i<n;i++)
	{
		if(adj[i]!=-1)
		{
			cout<<a[i]<<" "<<a[adj[i]]<<" "<<D[i]<<endl;
		}
	}
	cout<<"min length is:"<<len;
    return 0;
}
/*prims input
a b 5
a c 4
a d 1
b d 3
c d 2
e c 6
e d 7
a f 3
b f 2
*/
