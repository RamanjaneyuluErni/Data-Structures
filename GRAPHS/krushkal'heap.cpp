#include<iostream>
using namespace std;
int length=0;
int getindex(char s[],char c,int n)
{
	int i;
	for(i=1;i<=n;i++)
	if(s[i]==c)return i;
	return 0;
}
void printmat(int a[20][20],int n)
{
	int i,j;cout<<"your matrix is \n";
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
struct heap
{
	int p,q,w;
};
void swap(heap h[],int i,int j)
{
	int t1=h[i].p,t2=h[i].q,t3=h[i].w;
	h[i].p=h[j].p;h[i].q=h[j].q;h[i].w=h[j].w;
	h[j].p=t1;h[j].q=t2;h[j].w=t3;
}
void perculateup(heap H[],int p,int q,int w)
{
		H[length].p=p;H[length].q=q;H[length].w=w;
		int j=length;
		while(j!=1)
		{
			if(H[j].w<H[j/2].w)
			{
				swap(H,j,j/2);j=j/2;
			}
			else break;
		}
}
heap perculatedown(heap H[])
{
	heap r=H[1];
		H[1].p=H[length].p;
		H[1].q=H[length].q;
		H[1].w=H[length].w;length--;
		int j=1;
		while(2*j+1<=length)
		{
			if(H[2*j].w<H[2*j+1].w)
			{
				if(H[2*j].w<H[j].w)
				swap(H,j,2*j);j=2*j;
			}
			else
			{
				if(H[2*j+1].w<H[j].w)
				swap(H,j,2*j+1);j=2*j+1;
			}
		}
		return r;
}
int find(int a[],int i)
{
	if(a[i]==0)return i;
	return find(a,a[i]);
}
void createset(int a[],int i,int j)
{
	if(a[i]==0)
	a[i]=j;
	else if(a[j]==0)
	a[j]=i;
	else
	{
		if(a[find(a,i)]==0)
		a[find(a,i)]=j;
		else
		a[find(a,j)]=i;
	}
}
int main()
{
	int a[20][20],n,i,j,p;
	cout<<"enter number of vertices:";
	cin>>n;
	char ver[20],c,g;cout<<"enter names\n";
	for(i=1;i<=n;i++)
	cin>>ver[i];
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	a[i][j]=0;
	while(1)
	{
		cout<<"enter two vertices and their weight(! to stop)";
		cin>>c;
		if(c=='!')break;
		cin>>g;cin>>p;
		i=getindex(ver,c,n);j=getindex(ver,g,n);
		cout<<i<<","<<j<<endl;
		if(i==0||j==0){
			cout<<"not possible";continue;
		}
		a[i][j]=p;a[j][i]=p;
	}
	printmat(a,n);
	heap h[20];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i][j]){
				length++;a[j][i]=0;
			perculateup(h,i,j,a[i][j]);}
		}
		
	}
	int visit[20];
	for(i=1;i<=n;i++)visit[i]=0;
	heap k1=perculatedown(h);
	int dis[n+1];for(i=1;i<=n;i++)dis[i]=0;
	createset(dis,k1.p,k1.q);
	int cu[20],ne[20],we[20],len=1;
	cu[len]=k1.p;ne[len]=k1.q;we[len]=k1.w;len++;
	visit[k1.p]=1;visit[k1.q]=1;
	while(1)
	{
		heap k1=perculatedown(h);
		if(find(dis,k1.p)!=find(dis,k1.q)){
			visit[k1.p]=1;visit[k1.q]=1;
			createset(dis,k1.p,k1.q);
			cu[len]=k1.p;ne[len]=k1.q;we[len]=k1.w;len++;
			for(i=1;i<=n;i++)
			if(visit[i]==0)break;
			if(i==n+1)break;}
	}
	int sum=0;
	for(i=1;i<len;i++)
	{
		cout<<ver[cu[i]]<<" "<<ver[ne[i]]<<" "<<we[i]<<"\n";sum+=we[i];
	}
	cout<<"length="<<sum;
	return 0;
}

