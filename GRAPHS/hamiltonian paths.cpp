#include<iostream>
#include<queue>
using namespace std;
char a[20];int edge=0,isv[20],count=0;
void printqueue(queue<int>q)
{
	count++;
	while(q.size()!=0)
    {
		cout<<q.front()<<" ";q.pop();
	}
}
void printmatrix(int b[][20],int n)
{
	int i,j;
   cout<<"  ";for(i=1;i<=n;i++) cout<<i<<" ";cout<<endl;
   for(i=1;i<=n;i++)
	{
	   cout<<i<<" ";for(j=1;j<=n;j++) cout<<b[i][j]<<" ";cout<<endl;
    }
}
void hamiltonianpaths(int b[][20],int cv,int n,queue<int>q)
{
	q.push(cv);
	if(q.size()==n)
	{
		printqueue(q);cout<<endl;return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[cv][i] && isv[i]==0) 
		{
			isv[i]=1;
			hamiltonianpaths(b,i,n,q);
			isv[i]=0;
		}
	}
}
int main()
{
	int i,j,v,u,b[20][20],n;
	cout<<"no of vertices:";cin>>n;
	cout<<"enter vertices\n";
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) {isv[i]=0;for(j=1;j<=n;j++) b[i][j]=0;}
	cout<<"enter vertices to join(-1 to stop)\n";	
	while(1)
	{
		cin>>u;if(u==-1)break;cin>>v;
		b[u][v]=1;b[v][u]=1;edge++;
	}
    printmatrix(b,n);
    queue<int>q;
    cout<<"hamiltonian paths\n";
    for(i=1;i<=n;i++)
    {
    	isv[i]=1;
        hamiltonianpaths(b,i,n,q);
		for(j=1;j<=n;j++) isv[j]=0;
	}
    cout<<"count="<<count;
    return 0;
}
/*hamiltonian paths
a b c d e 
1 2
1 3
1 4
2 3
2 4
3 4
4 5
3 5
*/
