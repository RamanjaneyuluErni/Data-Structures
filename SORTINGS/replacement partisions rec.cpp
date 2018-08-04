#include<iostream>
using namespace std;
void sort(int &i,int &j,int &k)
{
	if(i<j)swap(i,j);if(i<k)swap(i,k);
	if(j<k)swap(j,k);
}
void replacement(int a[],int c,int &n)
{
	static int i,j,k;
	if(n>=10)
	{
		if(c==1) cout<<k<<" ";
		if(c==2)cout<<k<<" "<<j<<" ";
		if(c==3)cout<<k<<" "<<j<<" "<<i<<" ";
		return;
	}
	if(c==0)
	{
		i=a[n++];sort(i,j,k);replacement(a,c+1,n);return;
	}
	if(c==1)
	{
		j=a[n++];sort(i,j,k);replacement(a,c+1,n);return;
	}
	if(c==2)
	{
		k=a[n++];sort(i,j,k);replacement(a,c+1,n);return;
	}
	int r=a[n];
	if(r>=k)
	{
		cout<<k<<" ";k=r;n++;sort(i,j,k);replacement(a,c,n);return;
	}
	else
	{
		cout<<k<<" "<<j<<" "<<i<<endl;i=999;j=999;k=999;replacement(a,0,n);return;
	}
}
int main()
{
	int a[10]={3,10,5,6,2,11,1,19,6,17},c=0,i=0;
	replacement(a,c,i);
	return 0;
}
