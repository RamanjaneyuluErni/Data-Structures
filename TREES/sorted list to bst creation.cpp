#include<iostream>
#include<cmath>
using namespace std;
typedef
struct BSTnode{
	struct BSTnode *lc;
	int data;
	int tag;
	struct BSTnode *rc;
}*BSTptr;
int check(int n)
{
	int f=0,k=0;
	for(int i=0;i<n;i++)
	{
	  k=k+pow(2,i);	
	  if(k==n)f=1;
	  else if(k>n)break;
	}
	return f;
}
BSTptr creat(int a[],int b,int e)
{
	    BSTptr t=NULL;
	    if(b>e) return t;

	    t=new BSTnode;
     	t->data=a[(b+e)/2];
     	t->rc=NULL;
	    t->lc=NULL;t->tag=100;
		
	    t->lc=creat(a,b,(b+e)/2-1);
	    t->rc=creat(a,(b+e)/2+1 ,e);
	    return t;
}
void print (BSTptr &T)
{
	if(T==NULL) return;
	else
	{
		print(T->lc);cout<<T->data<<" ";print(T->rc);
	}		
}

int main()
{
	BSTptr T=NULL;
	int a[100],n,s,k,b=0;
	cout<<"size of an array\n";
	cin>>n;
	k=check(n);
	if(k==1)
	{
	   cout<<"possible\n";
   	   cout<<"enter sorted elements into array\n";
	   for(int i=0;i<n;i++)
	   cin>>a[i];
	   T=creat(a,b,n-1);
	   print(T);
    }
    else 
    {
	   cout<<"we can't make comptete bst\n";
	}
	return 0;
}
