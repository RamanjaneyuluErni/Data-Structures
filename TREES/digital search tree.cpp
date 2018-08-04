#include<iostream>
#include<cstring>
using namespace std;
typedef
struct dignode{
	struct dignode *lc;
	int *data;
	struct dignode *rc;
}
*digptr;


void create(digptr &t,int key[],int k,int p)
{
	if(t==NULL)
	{
		t=new dignode;
		t->lc=NULL;
		t->rc=NULL;
		t->data=new int[k];
		for(int i=0;i<k;i++) t->data[i]=key[i];
		
	}
	else
	{   int n=k;
		do{ 
		     p=(p+1)%k;
		     if(t->data[p]>key[p]) create(t->lc,key,k,p);
		     else if(t->data[p]<key[p]) create(t->rc,key,k,p);
		     
		  }while(t->data[p]==key[p] && --n>0);
		  
		  if(n==0) cout<<"elemnt repeated\n";
		
	}
}
void kdldr(digptr t,int k)
{
	if(t!=NULL)
	{
	kdldr(t->lc,k);
	for(int i=0;i<k;i++)
	cout<<t->data[i]<<"   ";
	
	}
	else return;
	kdldr(t->rc,k);
}

int digsearch(digptr t,int key[],int k,int r)
{
	if(t==NULL)return 0;
	else
	{
       int n=k;
      do
      {r=(r+1)%k;
      	if(t->data[r]>key[r])digsearch(t->lc,key,k,r);
      	else if(t->data[r]<key[r])digsearch(t->rc,key,k,r);
	  }while(t->data[r]==key[r]&&--n>0);
	  if(n==0)return 1;
	  else return 0;
	}
}
int main()
{
	digptr  T;
	int k,d;
	cout<<"enter no fo keys\n";
	cin>>k;
	int *key=new int[k];
	cout<<"enter "<<k<<" elements\n";
	for(int i=0;i<k;i++) cin>>key[i];
	T=new dignode;
	T->data=new int[k];
	for(int i=0;i<k;i++) T->data[i]=key[i];
	T->lc=NULL;T->lc=NULL;
	while(1)
	{  
	    digptr l=T;
		cout<<"enter 1 to continue 0 to break\n";
		cin>>d;
		if(d==0) break;
	    cout<<"enter "<<k<<" elements\n";
		for(int i=0;i<k;i++) cin>>key[i];
		create(l,key,k,-1);
	}
    kdldr(T,k);	
	return 0;
}

