#include<iostream>
using namespace std;
int d;
typedef
struct dlnode{
	           int data;
	           struct dlnode *left;
	           struct dlnode *right;
             }*dlptr;
typedef
struct bstnode{
	  int key;
	  struct bstnode *lc;
	  struct bstnode *rc;
	  dlptr ptr;
}*tptr;
void doublyll(dlptr &l)
{
	if(l==NULL)
	{
		cout<<"enter data(LL):";
		cin>>d;
		if(d==-1)return;
		l=new dlnode;
		l->data=d;
		l->left=NULL;
		l->right=NULL;
	}
	dlptr l1=l;
  while(1)
  {
  	while(l1->right!=NULL) l1=l1->right;
  	cout<<"enter data(LL):";
  	cin>>d;
  	if(d==-1)return;
  	l1->right=new dlnode;
  	dlptr l2=l1;
  	l1=l1->right;
  	l1->data=d;
  	l1->right=NULL;
  	l1->left=l2;
  }
}
void create(tptr &t,int d)
{
  if(t==NULL)
  {
    t=new bstnode;
	t->lc=NULL;
	t->rc=NULL;
	t->key=d;
	t->ptr=NULL;
	doublyll(t->ptr);
	}
   if(t->key>d) create(t->lc,d);
   else if(t->key<d)  create(t->rc,d);
}
void search(tptr &t,dlptr &l1,int d)
{
	if(t!=NULL) 
	{
		if(t->key>d) search(t->lc,l1,d); 
	    else if(t->key<d) search(t->rc,l1,d);
	    else
		{
			static dlptr l1=t->ptr;
			if(l1==NULL) return;
			cout<<l1->data<<" ";l1=l1->right;
		    search(t,l1,d);
		}
	}
	if(t==NULL)
	{
		cout<<"-1";return;
	}
}
int main()
{
	tptr t=NULL;dlptr l1=NULL;
	while(1)
	{
    	cout<<"enter key(in BST):";
    	cin>>d;
	    if(d==-1) break;
    	create(t,d);
   }
   cout<<"enter element to search:";
   cin>>d;
   search(t,l1,d);
	return 0;
}
