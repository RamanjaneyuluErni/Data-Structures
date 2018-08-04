#include<iostream>
#include<queue>
using namespace std;
typedef
struct bnode
{
	int count;
	int data[5];
	int tag;
	struct pointer
	{
		struct bnode *ptr[6]; //tag=0;
		struct bnode *PTR; //tag=1;
	}u;
}*BPTR;
BPTR getparentptr(BPTR &B,BPTR &T,int d)
{
	BPTR t=B;
    if(t==T) return NULL;
	else 
	{
		for(int i=0;i<=t->count+1;i++)
		{
		    if(t->tag==0&&t->u.ptr[i]==T) return t;
		}
		for(int i=0;i<=t->count;i++)
		{
			if(t->tag==0&&t->data[i]>d) return getparentptr(t->u.ptr[i],T,d);
		}
		if(t->tag==0)return getparentptr(t->u.ptr[t->count+1],T,d);
	}
}
void insertandsort(BPTR &B,BPTR &T,BPTR &C,int d);
void overflow(BPTR &B,BPTR &T)
{
	BPTR P=getparentptr(B,T,T->data[0]),temp;
	temp=new bnode;
	if(T->tag==1)
	{
		temp->tag=1;temp->count=2;
		temp->u.PTR=NULL;
		for(int i=2;i<=4;i++)
		{
		  temp->data[i-2]=T->data[i];
		}
		temp->u.PTR=T->u.PTR;
		T->u.PTR=temp;
	}
	else 
	{
		temp->tag=0;temp->count=1;
		for(int i=0;i<=5;i++) temp->u.ptr[i]=NULL;
		for(int i=3;i<=4;i++)
		{
		  temp->data[i-3]=T->data[i];
		  temp->u.ptr[i-3]=T->u.ptr[i];
		}
		temp->u.ptr[2]=T->u.ptr[5];
	}
	T->count=1;
	insertandsort(B,P,temp,T->data[2]);
}
void insertandsort(BPTR &B,BPTR &T,BPTR &C,int d)
{
    if(T==NULL)
	{
		T=new bnode;T->count=0;T->tag=0;T->data[0]=d;
		for(int i=0;i<=5;i++) T->u.ptr[i]=NULL;
		T->u.ptr[0]=B;T->u.ptr[1]=C;B=T;return;
	}
	int i=T->count;
	do 
	{
		if(T->data[i]<d) {T->data[i+1]=d;if(T->tag==0)T->u.ptr[i+2]=C;break;}
		T->data[i+1]=T->data[i];if(T->tag==0)T->u.ptr[i+2]=T->u.ptr[i+1];i--;
		
	}while(i>=0);
	if(i==-1)
	{
		T->data[0]=d;if(T->tag==0)T->u.ptr[1]=C;
	}
	T->count++;
	if(T->count==4) overflow(B,T);
}
BPTR getexactlocation(BPTR &B,int d)
{
	if(B->tag==1) return B;
	BPTR T=B;
	for(int i=0;i<=T->count;i++)
	{
		if(T->data[i]>d) return getexactlocation(T->u.ptr[i],d);
	}
	return getexactlocation(T->u.ptr[T->count+1],d);
}
void create(BPTR &B,int d)
{
	if(B==NULL)
	{
		B=new bnode;;B->tag=1;B->data[0]=d;
		B->count=0;B->u.PTR=NULL;return;
	}
	BPTR T=getexactlocation(B,d),C=NULL;
	insertandsort(B,T,C,d);
}
void levelprint(BPTR &B)
{
	BPTR C=NULL;queue<BPTR>q;
	q.push(B);q.push(C);
	while(q.size()!=0)
	{
		BPTR t=q.front();q.pop();cout<<"\t";
		if(t!=NULL)
		{
			for(int i=0;i<=t->count;i++)
			{
			   cout<<t->data[i]<<" ";
			   if(t->tag==0 && t->u.ptr[i]!=NULL) q.push(t->u.ptr[i]); 
			}
			if(t->tag==0 && t->u.ptr[t->count+1]!=NULL) q.push(t->u.ptr[t->count+1]);
			for(int i=0;i<3-t->count;i++) cout<<"-";
		}
		else
		{
			cout<<endl;
			if(q.size()!=0) q.push(C);
		}
	}
}
void printleaf(BPTR &B)
{
   if(B==NULL) return;
   BPTR t=B;
   if(t->tag==0) printleaf(t->u.ptr[0]);
   else 
   {
   	  for(int i=0;i<=t->count;i++) cout<<t->data[i]<<" ";
   	  printleaf(t->u.PTR);
   }
   
}
int main()
{
	BPTR B=NULL;int d;
	cout<<"enter data values(-1 to stop)\n";
	while(1)
	{
		cin>>d;
		if(d==-1)break;
		create(B,d);
		levelprint(B);cout<<endl;
	}
	cout<<"\nprint leaf nodes\n";
	printleaf(B);
	return 0;
}
