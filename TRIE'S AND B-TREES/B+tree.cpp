#include<iostream>
using namespace std;
typedef
struct bnode
{
	int count;
	int data[5];
	struct bnode *ptr[6];
}*bptr;
struct queue
{
	int front;
	int rear;
	int size;
	bptr ele[30];
}q;
void enque(struct queue &q,bptr &t)
{
	if(q.front==(q.rear+1)%q.size) cout<<"Q is full:";
	else
	{
		if(q.rear==-1)q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.ele[q.rear]=t;
	}
}
bptr deque(struct queue &q)
{
	if(q.front==-1) cout<<"Q is empty:";
	else
	{
		bptr temp=q.ele[q.front];
		if(q.front==q.rear)
		{
		   q.rear=-1;q.front=-1;
	    }
	    else q.front=(q.front+1)%q.size;
		return temp;
	}
}
bptr getparentptr(bptr &B,bptr T,int d)
{
	bptr t=B;
	if(t==NULL) return NULL;
	if(t==T) return NULL;
	else
	{
	  for(int i=0;i<=t->count+1;i++)
	  {
		if(t->ptr[i]==T) return t;
	  }
	   for(int i=0;i<=t->count;i++)
      {
	    	if(t->data[0]>d) return getparentptr(t->ptr[i],T,d);
	  }
	  return getparentptr(t->ptr[t->count+1],T,d);
   }	  
}
/*bptr getptr(bptr B,int el)
{
	if(B==NULL)return NULL;
	bptr l=B;int i;
	for(i=0;i<=l->count;i++)
	{
		if(l->data[i]==el)return(l);
		if(l->data[i]>el)return getptr(B->ptr[i],el);
	}
	return getptr(B->ptr[i],el);
}
bptr getparentptr(bptr B,bptr T)
{
		bptr l=B;int i;
		if(l==T)return NULL;
	for(i=0;i<=l->count;i++)
		if(l->data[i]>T->data[0])
		if(l->ptr[i]==T)return l;
		else return getparentptr(l->ptr[i],T);
	if(l->ptr[i]==T)return l;
	else return getparentptr(l->ptr[i],T);
}*/

void insertandsort(bptr &B,bptr &T,int d,bptr &C);
void overflow(bptr &B,bptr &T)
{
	bptr P=getparentptr(B,T,T->data[0]),temp;
	temp=new bnode;
	for(int i=0;i<=5;i++) temp->ptr[i]=NULL;
	if(T->ptr[0]==NULL)
	{
		temp->data[0]=T->data[2];
		temp->data[1]=T->data[3];
		temp->data[2]=T->data[4];
		temp->count=2;
		temp->ptr[5]=T->ptr[5];
		T->ptr[5]=temp;
	}
	else
	{
		temp->count=1;
		for(int i=3;i<=4;i++)
		{
			temp->data[i-3]=T->data[i];
			temp->ptr[i-3]=T->ptr[i];
		}
		temp->ptr[2]=T->ptr[5];
	}
	T->count=1;
    insertandsort(B,P,T->data[2],temp);
}
void insertandsort(bptr &B,bptr &T,int d,bptr &C)
{
	if(T==NULL)
	{
		T=new bnode;T->count=0;T->data[0]=d;
		for(int i=0;i<=5;i++) T->ptr[i]=NULL;
		T->ptr[0]=B;T->ptr[1]=C;B=T;return;
	}
	int i=T->count;
	do{
		   if(T->data[i]<d){T->data[i+1]=d;T->ptr[i+2]=C;break;}
		   T->data[i+1]=T->data[i];T->ptr[i+2]=T->ptr[i+1];i--;
	  }while(i>=0);
	if(i==-1)
	{
		T->data[0]=d;T->ptr[1]=C;
	}
	T->count++;
	if(T->count==4) overflow(B,T);
}
bptr getlocation(bptr &B,int d)
{
	if(B->ptr[0]==NULL)return B;
	for(int i=0;i<=B->count;i++)
	{
		if(B->data[i]>d) return getlocation(B->ptr[i],d);
	}
    return getlocation(B->ptr[B->count+1],d);	
}
void add(bptr &B,int d)
{
	if(B==NULL)
	{
		B=new bnode;B->data[0]=d;B->count=0;
		for(int i=0;i<=5;i++) B->ptr[i]=NULL;return;
	}
	bptr C=NULL,T=getlocation(B,d);
	insertandsort(B,T,d,C);
}
void levelprint(bptr B)
{
	q.front=-1;q.rear=-1;q.size=30;
	bptr C=NULL;
	enque(q,B);	enque(q,C);
	while(1)
	{
		bptr t=deque(q);cout<<"\t";
		if(t!=NULL)
		{
			for(int i=0;i<=t->count;i++) cout<<t->data[i]<<" ";
			for(int i=0;i<=t->count+1;i++)
			{
				if(t->ptr[i]!=NULL) enque(q,t->ptr[i]);
			}
			for(int i=0;i<3-t->count;i++) cout<<" _ ";
		}
		else
		{
			cout<<endl;
			if(q.front==-1)break;
			enque(q,C);
		}
	}
}
void printleaf(bptr &t)
{    
    bptr B=t; 
	while(B->ptr[0]!=NULL) B=B->ptr[0];
	while(1)
	{
		for(int i=0;i<=B->count;i++) cout<<B->data[i]<<" ";
		if(B->ptr[5]==NULL) break;
		B=B->ptr[5];
	}
}
void delleaf(bptr &t,int d)
{
	bptr B=t;int f=0;
	while(B->ptr[0]!=NULL) B=B->ptr[0];
	while(1)
	{
		for(int i=0;i<=B->count;i++) 
		{
		   if(B->data[i]==d)
		   {
		   	 if(B->count>1)
		   	 {
		   	 	f=2;
				for(int j=i;j<=B->count;j++) 
				{
					B->data[j]=B->data[j+1];
				}B->count--;break;
			 }
			 else {f=1;break;}
		   }
	     }
		if(B->ptr[5]==NULL || f==2 ||f==1) break;
		B=B->ptr[5];
	}
	if(f==1) cout<<"not possible to delete:";
	if(f==0) cout<<"not found:";
}
int main()
{
	bptr B=NULL;int d;
	cout<<"enter data values\n";
	while(1)
	{
		cin>>d;
		if(d==-1)break;
		add(B,d);
		levelprint(B);
	}
cout<<endl;
printleaf(B);
cout<<"\nenter element to delete:";
cin>>d;
delleaf(B,d);
printleaf(B);
	return 0;
}
