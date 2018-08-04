#include<iostream>
#include<queue>
using namespace std;
int b[20][20],n,count=0,edge=0;
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
void printpaths(int cv,queue<int>q)
{
	q.push(cv);
	if(degree(cv)==0)
	{
		if(q.size()==edge+1) printqueue(q);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[cv][i]!=0)
		{
			b[cv][i]=0;b[i][cv]=0;printpaths(i,q);
			b[cv][i]=1;b[i][cv]=1;
		}
	}
}
int main()
{
	
	int i,j,k,v,u;char c1,c2;
	cout<<"no of vertices:";cin>>n;
	for(i=1;i<=n;i++) 	{ for(j=1;j<=n;j++) b[i][j]=0; }
	cout<<"enter vertices to join(-1 to stop)\n";	
	while(1)
	{
		cin>>u;if(u==-1)break;cin>>v;
		b[u][v]=1;b[v][u]=1;edge++;
	}
    printmatrix();
    queue<int>q;
    while(1)
    {
    	cout<<"\nenter start vertex(from 1 to n):";cin>>v;
        printpaths(v,q);
        cout<<"\ntotal no of paths:"<<count;
	}
    
    return 0;
}
/*euler all paths
1 3
1 4
2 3
2 8
8 9
9 6
6 3
3 9
3 4
3 7
9 7
9 10
9 12
12 10
7 10
7 4
4 10
4 11
10 11
10 5
4 5
*/
