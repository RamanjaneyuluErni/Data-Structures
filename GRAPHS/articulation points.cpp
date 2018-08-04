#include<iostream>
using namespace std;
int no=1,prenum[20],bedge[20],parent[20],isv[20],lnum[20];char a[20];
void printmatrix(int b[][20],int n)
{
	int i,j;
   cout<<"  ";for(i=1;i<=n;i++) cout<<i<<" ";cout<<endl;
   for(i=1;i<=n;i++)
	{
	   cout<<i<<" ";for(j=1;j<=n;j++) cout<<b[i][j]<<" ";cout<<endl;
    }
}
int checkvisit(int b[][20],int cv,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(b[cv][i]==1 && isv[i]==0) return 1;
	}
	return 0;
}
void printpaths(int b[][20],int n,int cv)
{
	if(checkvisit(b,cv,n)==0) return;
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(b[cv][i]==1 && isv[i]==0)
			{
				isv[i]=1;prenum[i]=++no;parent[i]=cv;
				for(int j=1;j<=n;j++)
				{
					if(b[i][j]==1 && isv[j]==1 && j!=cv) {if(bedge[i]>prenum[j])bedge[i]=j;} 
				}
				printpaths(b,n,i);
			}
			
		}
	}
}
void lownumber(int n,int a)
{
	int min=999;
	for(int i=1;i<=n;i++) { if(parent[i]==a && lnum[i]<min) min=lnum[i];}
	if(bedge[a]!=999 && prenum[bedge[a]]<min) min=prenum[bedge[a]];
	if(min==999) min=prenum[a];
	lnum[a]=min;
}
void articulationpts(int b[][20],int v,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(i==v) 
		{
			int c=0;for(int k=1;k<=n;k++) if(parent[k]==i) c++;
			if(c>=2) cout<<a[i]<<"  ";
		}
		else
		{
			for(int k=1;k<=n;k++) 
			{
				if(parent[k]==i && lnum[k]>=prenum[i]) cout<<a[i]<<"  ";
			}
		}
		
	}
}
int main()
{
	int i,j,v,u,b[20][20],n;
	cout<<"no of vertices:";cin>>n;
	cout<<"enter vertices\n";
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) { isv[i]=0;bedge[i]=999;prenum[i]=0;parent[i]=0;for(j=1;j<=n;j++) b[i][j]=0;}
	cout<<"enter vertices to join(-1 to stop)\n";	
	while(1)
	{
		cin>>u;if(u==-1)break;cin>>v;
		b[u][v]=1;b[v][u]=1;
	}
    printmatrix(b,n);
    cout<<"enter start vertex:";cin>>v;
    isv[v]=1;bedge[v]=999;prenum[v]=1;parent[v]=0;
    printpaths(b,n,v);
    for(i=no;i>0;i--)
    {
  	   for(j=1;j<=n;j++) if(i==prenum[j]) break;
   	   lownumber(n,j);
	}
    cout<<"\nvertex\tprenum\tparent\tbedge\tlow-num\n";
    for(i=1;i<=n;i++) 
    {
    	cout<<a[i]<<"\t"<<prenum[i]<<"\t"<<parent[i]<<"\t"<<bedge[i]<<"\t"<<lnum[i]<<endl;
	}
	cout<<endl;
	articulationpts(b,v,n);
    return 0;
}
/*articulation point(input)
a b c d e f g
1 2
1 4
2 3
3 4
4 5
4 6
6 5
3 7
*/
