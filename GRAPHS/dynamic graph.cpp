#include<iostream>
using namespace std;
typedef
struct lnode
{
	struct gnode *PTR;
	struct lnode *next;
}*LPTR;
typedef
struct gnode
{
	char data;
	struct gnode *gptr;
	LPTR ptr;
}*GPTR;
void addptr(GPTR &L,GPTR &T,char d)
{
	while(T!=NULL)
	{
		if(T->data==d) break;
		T=T->gptr;
	}
	GPTR t=L;
	if(t->ptr==NULL)
   {
   	 t->ptr=new lnode;
   	 t->ptr->PTR=T;t->ptr->next=NULL;return;
   }
   LPTR l=L->ptr;
   while(l->next!=NULL) l=l->next;
   l->next=new lnode;
   l=l->next;
   l->PTR=T;l->next=NULL;
}

void create(GPTR &G,char &ch)
{
	if(G==NULL)
	{
		G=new gnode;G->data=ch;
		G->gptr=NULL;
		G->ptr=NULL;return;
	}
	GPTR T=G;
	while(T->gptr!=NULL) T=T->gptr;
	T->gptr=new gnode;
	T=T->gptr;
	T->data=ch;
	T->gptr=NULL;
	T->ptr=NULL;
}
void addedge(GPTR &G)
{
	char d;
	GPTR t=G;
	while(t!=NULL) 
	{
		cout<<"enter vertices which are adjacent:"<<t->data<<endl;
		while(1)
		{
			cin>>d;if(d=='n') break;
			GPTR T=G;
			addptr(t,T,d);
		}
		t=t->gptr;
	}
}
void printgraph(GPTR T)
{
	GPTR G=T;
	while(G!=NULL)
	{
		cout<<G->data<<":";
		LPTR L=G->ptr;
		while(L!=NULL)
		{
			cout<<L->PTR->data<<" ";
			L=L->next;
		}
		cout<<endl;
		G=G->gptr;
	}
}
int main()
{
	GPTR G=NULL;char ch;
	while(1)
	{
	  cout<<"enter vertex:('n' to stop)";cin>>ch;
	  if(ch=='n')break;
	  create(G,ch);
	}
	addedge(G);
	cout<<"printing graph\n";
	printgraph(G);
	return 0;
}
