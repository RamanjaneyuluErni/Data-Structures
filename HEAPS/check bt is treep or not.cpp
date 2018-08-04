#include<iostream>
using namespace std;
typedef
struct tnode{
	int data;
	int d;
	struct tnode *lc;
	struct tnode *rc;
}*tptr;
void create(tptr &t,int d,int ch)
{
	if(t==NULL)
	{
		t=new tnode;
		t->data=d;
		t->d=ch;
		t->lc=NULL;
		t->rc=NULL;
	}
	cout<<"enter LC of "<<t->data<<"(-1 to stop):";
	cin>>d;
    if(d!=-1)
	{
      	cout<<"enter LC of "<<t->data<<"(-1 to stop):";
	     cin>>ch;
	    create(t->lc,d,ch);
     }
	cout<<"enter RC of "<<t->data<<"(-1 to stop):";
	cin>>d;
	if(d!=-1)
	{
		cout<<"enter LC of "<<t->data<<"(-1 to stop):";
	    cin>>ch;
	    create(t->rc,d,ch);
    }
}
int check(tptr &t)
{
	if(t==NULL) return 0;
	else 
	{
	   if(t->lc==NULL && t->rc!=NULL) return 1;
	   if (t->lc!=NULL && t->lc->d<t->d ) return 1;
	   if (t->rc!=NULL && t->rc->d<t->d) return 1;
	   if(t->rc!=NULL && t->data>=t->rc->data || t->lc!=NULL && t->data<=t->lc->data) return 1;
	   else return(check(t->lc)+check(t->rc));
	}	
}
int main()
{
	tptr t1;t1=NULL;int d,ch;
	  cout<<"enter data(-1 to stop):";
	  cin>>d;
	  cout<<"enter data:";
	  cin>>ch;
	  create(t1,d,ch);
	if(check(t1)>0)
	cout<<"not treap:";
	else
	cout<<"yes";
	return 0;
}
