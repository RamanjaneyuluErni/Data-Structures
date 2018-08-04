#include<iostream>
#include<cstring>
using namespace std;
char a[10];int b[10][10],V[10],len=0,f[10][10],size=0;
struct heapnode
{
	int weight;
	int p;
	int q;
};
void swap(int x,int y,heapnode h[])
{
	int t1=h[x].weight,t2=h[x].p,t3=h[x].q;
	h[x].weight=h[y].weight;h[x].p=h[y].p;h[x].q=h[y].q;
	h[y].weight=t1;h[y].p=t2;h[y].q=t3;
}
void printmatrix(int n)
{
   cout<<"  ";
   for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
   for(int i=1;i<=n;i++)
	{
	   cout<<a[i]<<" ";
	   for(int j=1;j<=n;j++) cout<<b[i][j]<<" ";cout<<endl;
    }
}  
int addedge(char c1,char c2,int n,int wt)
{
	int v,u;
	for(v=1;v<=n;v++) if(a[v]==c1) break;if(v==n+1) return n+1;
	for(u=1;u<=n;u++) if(a[u]==c2) break;if(u==n+1) return n+1;
	b[v][u]=wt;b[u][v]=wt;
	cout<<"edge added b/w "<<a[v]<<" and "<<a[u]<<endl;
	return -1;
}
/*void printheap(heapnode h[])
{
	for(int i=1;i<=size;i++)
	{
			cout<<h[i].p<<"  "<<h[i].q<<":"<<h[i].weight<<endl;
	} 
}*/
void perculateup(heapnode h[],int v,int u)
{
	 size++;
	 h[size].p=v;h[size].q=u;h[size].weight=b[v][u];
	 int j=size;
	 while(j!=1)
	 {
	 	if(h[j].weight<h[j/2].weight)
	 	{
	 		swap(j,j/2,h);j=j/2;
		}
		else break;
	 }
}
void perculatedown(heapnode h[])
{
  if(size==1) size=0;
  else if(size==2){ swap(1,2,h);size--;}
  else
  {
	swap(1,size,h);size--;int j=1;  
	while(j<=size)  
	{
	  if(h[j].weight>h[j*2].weight || h[j].weight>h[2*j+1].weight)	    
	  {           
	    if(size==2) {swap(1,2,h);return;}
		if(h[2*j].weight<h[2*j+1].weight) {if(2*j<=size) swap(j,2*j,h);j=2*j;}	       
		else{if(2*j+1<=size) swap(j,2*j+1,h);j=2*j+1;}
	  }
	  else break;
	}
  } 
}
int main()
{
	int wt,i,j,k,n,v;char c1,c2;
	cout<<"no of vertices:";cin>>n;
	cout<<"enter vertices\n";
	for(i=1;i<=n;i++) 
	{
	   cin>>a[i];V[i]=0;for(j=1;j<=n;j++) {b[i][j]=0;f[i][j]=0;}
	}
	struct heapnode h[n];
	cout<<"enter vertices to join(# to stop)\n";
    while(1)
	{
		cin>>c1;if(c1=='#') break;cin>>c2;
		cout<<"enter weight:";cin>>wt;
		if(addedge(c1,c2,n,wt)==n) cout<<"vertex not found:\n";
	}
	printmatrix(n);
	cout<<"enter start vertex:";cin>>v;
	int cv=v;
	while(1)
	{
		int c=0;V[cv]=1;
    	for(k=1;k<=n;k++) { if(V[k]==1) c++;}
		if(c==n) break;
		for(int i=1;i<=n;i++)
		{
			if(b[cv][i]!=0 && V[i]==0){perculateup(h,cv,i);}
		}
        while(1)
        {
        	if(size==0) break;
        	int x=h[1].p,y=h[1].q,z=h[1].weight;
        	perculatedown(h);
        	if(V[y]!=1) { f[x][y]=z;cv=y;break;}
		}
		cout<<"current vertex:"<<cv<<endl;
        if(size==0) break;
	}
	cout<<"printing min path"<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++){if(f[i][j]!=0) {len=len+f[i][j];cout<<a[i]<<" "<<a[j]<<" "<<f[i][j]<<endl;}}
	}
    cout<<"min length:"<<len;
    return 0; 
}
/*prims using heaps
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
