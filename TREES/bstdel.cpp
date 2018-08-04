#include<iostream>
#include<iomanip>
int k=0;
using namespace std;
struct bstnode
{
	struct bstnode *lchild;
	int data,no;
	struct bstnode *rchild;
};
typedef bstnode *BSTPTR;
struct queue
{
	int front;
	int rear;
	BSTPTR elements[20];
	int size;
};
void enque(struct queue &q,BSTPTR t)
{
	if((q.rear+1)%q.size==q.front)cout<<"queue is full";
	else
	{
		if(q.front==-1)q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.elements[q.rear]=t;
	}
}
BSTPTR deque(struct queue &q)
{
	if(q.front==-1)cout<<"queue is empty";
	else
	{
		BSTPTR t=q.elements[q.front];
		if(q.front==q.rear)
		{
			q.front=-1;q.rear=-1;
		}
		else q.front=(q.front+1)%q.size;
		return t;
	}
}
void insert(BSTPTR &T,int n)
{
	if(T==NULL)
	{
		T=new(bstnode);T->data=n;T->lchild=NULL;T->rchild=NULL;
	}
	else
	{
		if(T->data>n)insert(T->lchild,n);
		else insert(T->rchild,n);
	}
}

int del(BSTPTR &T,BSTPTR &k)
{
	if(k->lchild==NULL&&k->rchild==NULL)
	{
		BSTPTR m=T;cout<<"ok";
        while(1)
        {
        	if(m->lchild!=NULL)
        	{
        		if(m->lchild->data==k->data)break;
        		if(k->data<m->data)m=m->lchild;
			}
			if(m->rchild!=NULL)
			{
				if(m->rchild->data==k->data)break;
				if(k->data>m->data)m=m->rchild;
			}
		}
		if(m->lchild!=NULL)if(m->lchild->data==k->data)m->lchild=NULL;
		else m->rchild=NULL;
		int a=k->data;
		delete(k);return a;
	}
	else
	{
		int a=k->data;
		if(k->lchild!=NULL)
		{
			BSTPTR l=k->lchild;
			while(l->rchild!=NULL)l=l->rchild;
			k->data=del(T,l);
		}
		else
		{
			BSTPTR l=k->rchild;
			while(l->lchild!=NULL)l=l->lchild;
			k->data=del(T,l);
		}
		return a;
	}
}
void dele(BSTPTR &T,int el)
{
	BSTPTR l=T;
	while(l->data!=el)
	{
		if(l->data>el)l=l->lchild;
		else l=l->rchild;
	}
	int a=del(T,l);
}
void printldr(BSTPTR T)
{
	if(T!=NULL)
	{
		printldr(T->lchild);
		cout<<T->data<<"  ";
		printldr(T->rchild);
	}
}
void numberldr(BSTPTR &T)
{
	if(T!=NULL)
	{
		numberldr(T->lchild);
		T->no=k++;
		numberldr(T->rchild);
	}
}
void getspace(int n)
{
	while(--n>=0)cout<<" ";
}
void levelprintsame(BSTPTR T)
{
	struct queue q;
	q.size=20;q.front=-1;q.rear=-1;
	BSTPTR l,t;l=new(bstnode);l->data=-1;l->lchild=NULL;l->rchild=NULL;l->no=-1;
	enque(q,T);enque(q,l);int s=0;
	while(q.front!=-1)
	{
		t=deque(q);
		if(t==l)
		{
			cout<<endl<<endl;if(q.front!=-1)enque(q,l);s=0;
		}
		else
		{
			getspace(t->no-s);
			cout<<setw(2)<<t->data;
			s=t->no+2;
			if(t->lchild!=NULL)enque(q,t->lchild);
			if(t->rchild!=NULL)enque(q,t->rchild);
		}
	}
}
int find(BSTPTR T,int k)
{
	if(T!=NULL)
	{
		if(T->data==k)return 1;
		else if(T->data>k)return(find(T->lchild,k));
		else return(find(T->rchild,k));
	}
	return 0;
}
int main()
{
	BSTPTR T;T=NULL;
	int n;
	cout<<"enter values to keep in tree(-1 to stop):\n";
	while(1)
	{
		cin>>n;
		if(n==-1)break;
		insert(T,n);
	}
	cout<<"Your tree is:\n";numberldr(T);levelprintsame(T);
	cout<<"\nLDR print is: ";printldr(T);
	cout<<"\nenter a value to delete: ";
	cin>>n;
	if(find(T,n)!=1)cout<<"not found";
	else
	{
		dele(T,n);
		cout<<"Your tree is:\n";numberldr(T);levelprintsame(T);
		cout<<"\nLDR print is: ";printldr(T);
	}
}
