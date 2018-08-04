#include<iostream>
using namespace std;
typedef
struct bstnode{
	int data;
	struct bstnode *lc;
	struct bstnode *rc;
}*bstptr;
typedef
struct lnode{
	
			int data;
			struct lnode *next;
			bstptr ptr;
}*lptr;
void create(lptr &l)
{
	int d;
	cout<<"enter in ascending order:\n";
	cout<<"enter data(-1 to stop):";
	cin>>d;
	if(d==-1)return;
	    l=new lnode;
		l->data=d;
		l->next=NULL;
		l->ptr=NULL;
   lptr t=l;
   while(1)
	{
	   while(t->next!=NULL)t=t->next;
	   cout<<"enter data(-1 to stop):";
	   cin>>d;
	   if(d==-1)return;
       t->next=new lnode;
	   t->next->data=d;
	   t->next->next=NULL;
	   t->next->ptr=NULL;
      }
}
void add(bstptr &t,int d)
{
	if(t==NULL)
	{
		t=new bstnode;
		t->data=d;
		t->lc=NULL;
		t->rc=NULL;
		return;
	}
	if(t->data>d) add(t->lc,d);
	else if(t->data<d) add(t->rc,d);
	
}
void treecreat(lptr &l,int d)
{
	lptr l1=l;
	lptr l2=l1->next;
	while(1)
	{
		if(l2==NULL) 
		{
		   add(l1->ptr,d);return;
	    }
		else if(l1->data<d && l2->data>d)
		{
		    add(l1->ptr,d);return;
		}
		l1=l1->next;
		l2=l2->next;
	}
}
/*void printtree (bstptr &T)
{
	if(T!=NULL)
	  {
   	    printtree(T->lc);
		cout<<T->data<<" ";
	  }
	  else return;
	  printtree(T->rc);
}
void print(lptr &T)
{
	lptr l=T;
	while(l->next!=NULL)
	{
		cout<<l->data<<" - "<<l->next->data<<":";
		printtree (l->ptr);cout<<endl;
		l=l->next;
	}
	cout<<l->data<<" - "<<":";
	printtree (l->ptr);
	
}*/
int search(lptr &l,bstptr &t,int lb,int ub,int n)
{
  if(l==NULL) return -1;
  else if(l->data==lb && l->next->data==ub)
   {
   	   if(t==NULL) return -1;
	   if(t->data==n) return t->data;
	   else if(t->data>n)
	   search(l,t->lc,lb,ub,n); 
	   else
	   search(l,t->rc,lb,ub,n);
  }
  else search(l->next,l->next->ptr,lb,ub,n);
}
/*void print(lptr &l,bstptr &t,int &k)
{
	if(l==NULL) return;
	else 
	{
		if(k==0)
		{
		  cout<<l->data<<" - ";
		  if(l->next!=NULL) cout<<l->next->data<<":";
		  k++;
		}
		if(t!=NULL) 
		{
			print(l,t->lc,k);
			cout<<t->data<<" ";
		    print(l,t->rc,k);
	    }
	}
	k=0;
	print(l->next,l->next->ptr,k);
} */
int main()
{
	lptr l=NULL;int d,k=0;bstptr t=NULL;
	create(l);
	while(1)
	{   lptr l1=l;
		cout<<"enter data(-1 to stop)tree:";
		cin>>d;
		if(d==-1)break;
		treecreat(l1,d);
	}
// print(l,l->ptr,k);
 int n,lb,ub;
 cout<<"enter lb:";cin>>lb;
 cout<<"enter ub:";cin>>ub;
 cout<<"enter no to search:";cin>>n;
 if(search(l,t,lb,ub,n)==-1)
 cout<<"not found:";
 else
 cout<<"found:"<<search(l,l->ptr,lb,ub,n);
	return 0;
}
