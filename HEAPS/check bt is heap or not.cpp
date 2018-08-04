#include<iostream>
using namespace std;
typedef
struct tnode{
	int data;
	struct tnode *lc;
	struct tnode *rc;
}*tptr;
void create(tptr &t,int d,)
{
	if(t==NULL)
	{
		t=new tnode;
		t->data=d;
		t->lc=NULL;
		t->rc=NULL;
	}
	cout<<"enter LC of "<<t->data<<"(-1 to stop):";
	cin>>d;
	if(d!=-1)
	create(t->lc,d);
	cout<<"enter RC of "<<t->data<<"(-1 to stop):";
	cin>>d;
	if(d!=-1)
	create(t->rc,d);
}
int check(tptr &t)
{
	if(t==NULL) return 0;
	else 
	{
	   if(t->lc==NULL && t->rc!=NULL) return 1;
	   if (t->lc!=NULL && t->lc->data<t->data ) return 1;
	   if (t->rc!=NULL && t->rc->data<t->data) return 1;
	   else return(check(t->lc)+check(t->rc));
	}	
}
int main()
{
	tptr t1;t1=NULL;int d;
	cout<<"enter root data:";
	cin>>d;
	create(t1,d);
	if(check(t1)>0)
	cout<<"not heap:";
	else
	cout<<"yes";
	return 0;
}
