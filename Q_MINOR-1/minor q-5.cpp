#include<iostream>
using namespace std;
typedef
struct btnode{
	struct btnode *lc;
	int data;
	struct btnode *rc;
}*tptr;
tptr create(tptr &t,int a[],int n,int i)
{
	if(n==0) return NULL;
	else {
		   t=new btnode;
		   t->data=a[i];
		   t->lc=NULL;
		   t->rc=NULL;
		   if(2*i<=n) create(t->lc,a,n,2*i);
		   if(2*i+1<=n) create(t->rc,a,n,2*i+1);
	     }
	return t;
}
void print (tptr &T)
{
	if(T!=NULL)
	{
      	print(T->lc);
		cout<<T->data<<" ";
	}
    else return;
    print(T->rc);
   
}
int max(tptr &t)
{
	if(t==NULL)
	return -1;
	else 
	return(max(t->lc)>max(t->rc) ?max(t->lc)>t->data?max(t->lc):t->data : max(t->rc)>t->data?max(t->rc):t->data);  
}
int main()
{
	tptr t=NULL;int m=0;
   int n,a[30],i=1;
   cout<<"enter size:";cin>>n;
   cout<<"enter heap elements:\n";
   for(int i=1;i<=n;i++)
    cin>>a[i];
  tptr T=create(t,a,n,1);
  print(T);
  cout<<"\nmax value:"<<max(T);
   return 0;
}
