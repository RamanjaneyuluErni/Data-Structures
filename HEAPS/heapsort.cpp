#include<iostream>
#include<limits.h>
using namespace std;
void swap(int &x,int &y)
{
	int t=x;
	x=y;y=t;
}
void perculateup(int a[],int size)
{
	cout<<"heap elements\n";
	for(int i=1;i<size;i++)
	{
		cin>>a[i];int j=i;
		while(j!=1)
		{
			if(a[j]<a[j/2])
			{
				swap(a[j],a[j/2]);j=j/2;
			}
			else break;
		}
	}
	for(int i=1;i<size;i++)	cout<<a[i]<<" ";
}
void perculatedown(int a[],int n)
{
	int j=1;
	while(j<n)
	{
		if(a[j]>a[j*2] ||a[j]>a[2*j+1])
		{
			if(a[2*j]<a[2*j+1])
			{
				if(2*j<=n)
				swap(a[j],a[2*j]);
				j=2*j;
			}
			else
			{
				if(2*j+1<=n)
				swap(a[j],a[2*j+1]);
				j=2*j+1;
			}
		}
		else break;
	}
}
void heapsort(int a[],int n,int j)
{
	while(n>=1)
	{
		if(n==1)
		{
			cout<<a[j]<<" ";break;
		}
		else if(n==2)
		{
		 cout<<a[j+1]<<" ";n--;
	    }
		else
		{
			cout<<a[j]<<" ";
			swap(a[j],a[n]);
			n--;
			perculatedown(a,n);
		}
	}
}

int check(int a[],int n,int i,int el)
{
	if(i>n || a[i]>el) return 0;
	else if(a[i]==el) return i;
	else return (check(a,n,2*i,el)+check(a,n,2*i+1,el));
	
}
int delet(int a[],int n,int index)
{
	a[index]=INT_MIN;
	while(index>=1)
	{
		if((index/2)>=1 && a[index]<a[index/2]) 
		{
			swap(a[index],a[index/2]);index/=2;
		}
		else break;
	}
}
int main()
{
    int size,a[30],i=1;
    cout<<"enter size:";cin>>size;
	perculateup(a,size);
	//cout<<"\nheap sorting:";
	//heapsort(a,size-1,i);
	while(true) {
		 cout<<"enter element to delete:";
	     cin>>i;if(i==-1) break;
	    int x=check(a,size-1,1,i);
     	if(x>0) 
		  {
		  	delet(a,size-1,x);size--;
		  	cout<<x<<"\t\tdeleted";
		  	for(int p=0;p<=size;p++) cout<<a[p]<<" ";
		  	cout<<endl;
		  }
    	else cout<<"not found";
	}
	
    return 0;
}
