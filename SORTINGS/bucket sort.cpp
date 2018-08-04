#include<iostream>
#include<cmath>
using namespace std;
int c=0;
typedef
struct lnode
{
	int data;
	struct lnode *next;
}*lptr;
typedef
struct bucketlist
{
	int index;
	lptr PTR;
	struct bucketlist *next;
}*bptr;
void print(bptr &t)
{
    bptr l=t;cout<<"anji1-----";
	while(l!=NULL) 
	{cout<<"anji2-----";
	  if(l->PTR!=NULL)
	  {
	  	lptr l1=l->PTR;cout<<"anji3-----";
	  	while(l1!=NULL){ cout<<l1->data<<"  ";cout<<"anji7-----";l1=l1->next;}
	  }cout<<"anji4-----";
	  l=l->next;
	}cout<<"anji5-----";
}
void maxdigits(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		int p=0,k=a[i];while(k!=0)	{ p++;k=k/10;}
		if(p>c) c=p;
	}
}
void addllist(bptr &B,int d,int key)
{
	bptr L=B;cout<<"2-----";
	for(int i=0;i<d;i++) L=L->next;cout<<"3-----";
	lptr l=L->PTR;
	while(l!=NULL)l=l->next;cout<<"4-----";
	l=new lnode;l->data=key;l->next=NULL;cout<<"5-----";
}
void bucketsort(bptr &B,int a[],int n)
{
	int d,k;
	 for(int j=0;c!=0;j++,c--)
	 {
	 	for(int i=0;i<n;i++)
	 	{
	 	  k=a[i];k=k/pow(10,j);d=k%10;
	 	  cout<<"1-----";
		  addllist(B,d,a[i]);	
		}
	 }
}
int main()
{
	int a[30],n;
	cout<<"enter no of elemnts:";cin>>n;
	cout<<"enter elements to sort\n";
	for(int i=0;i<n;i++) cin>>a[i];
	maxdigits(a,n);
	cout<<"elments before sorting:";
	for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
	bptr B=NULL;B=new bucketlist;B->index=0;B->PTR=NULL;B->next=NULL;
	for(int i=1;i<10;i++)
	{
		bptr T=B;
		while(T->next!=NULL) T=T->next;
		T->next=new bucketlist;T->next->index=i;T->next->PTR=NULL;T->next->next=NULL;
	}
	bucketsort(B,a,n);
	print(B);
	return 0;
}
