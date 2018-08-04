#include<iostream>
using namespace std;
typedef
struct kdnode
{
	struct kdnode *lchild;
	int *data;
	struct kdnode *rchild;
}*kdptr;
void kdldr(kdptr t,int k)
{
	if(t!=NULL)
	{
	kdldr(t->lchild,k);
	for(int i=0;i<k;i++)
	cout<<t->data[i]<<" ";cout<<"  ";
	kdldr(t->rchild,k);
	}
}
void kdcreate(kdptr &t,int key[],int k,int r)
{
	if(t==NULL)
	{t=new(kdnode);t->lchild=NULL;t->rchild=NULL;
	t->data=new(int [k]);
	for(int i=0;i<k;i++)t->data[i]=key[i];}
	else
	{ int n=k;
      do
      {r=(r+1)%k;
      	if(t->data[r]>key[r])kdcreate(t->lchild,key,k,r);
      	else if(t->data[r]<key[r])kdcreate(t->rchild,key,k,r);
	  }while(t->data[r]==key[r]&&--n>0);
	  if(n==0)cout<<"sorry the element exists\n";
	}
}
int kdsearch(kdptr t,int key[],int k,int r)
{
	if(t==NULL)return 0;
	else
	{
       int n=k;
      do
      {r=(r+1)%k;
      	if(t->data[r]>key[r])kdsearch(t->lchild,key,k,r);
      	else if(t->data[r]<key[r])kdsearch(t->rchild,key,k,r);
	  }while(t->data[r]==key[r]&&--n>0);
	  if(n==0)return 1;
	  else return 0;
	}
}
int main()
{
	int i,n,k;
	kdptr t,l;
	t=new(kdnode);t->lchild=NULL;t->rchild=NULL;
	cout<<"enter number of keys: ";
	cin>>k;
	int *key=new(int [k]);
	t->data=new(int [k]);
		cout<<"enter "<<k<<" elements\n";
		for(i=0;i<k;i++)cin>>t->data[i];
		
	while(1)
	{
	    l=t;
		cout<<"do u want to create?(1 or 0): ";
		cin>>n;
		if(n==0)break;
		cout<<"enter "<<k<<" elements\n";
		for(i=0;i<k;i++)cin>>key[i];
		kdcreate(l,key,k,-1);
	}
	kdldr(t,k);
	cout<<"\nenter "<<k<<" element to search\n";
	for(i=0;i<k;i++)cin>>key[i];
	if(kdsearch(t,key,k,-1)==1)
	cout<<"found";
	else cout<<"not found";
	return 0;
}
