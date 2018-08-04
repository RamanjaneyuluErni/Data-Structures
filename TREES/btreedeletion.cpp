#include<iostream>//B2-TREE
using namespace std;
int non=0;
typedef
struct bnode
{
	int count;
	int data[5];
	bnode *ptr[6];
}*BPTR;
void printinorder(BPTR B)
{
	if(B==NULL)return;
	for(int i=0;i<=B->count;i++)
	{
		printinorder(B->ptr[i]);
		cout<<B->data[i]<<"  ";
	}
	printinorder(B->ptr[B->count+1]);
}
struct queue
{
	int front;
	int rear;
	BPTR elements[30];
	int size;
};
void enque(struct queue &q,BPTR t)
{
	if((q.rear+1)%q.size==q.front)cout<<"queue is full";
	else
	{
		if(q.front==-1)q.front=0;
		q.rear=(q.rear+1)%q.size;
		q.elements[q.rear]=t;
	}
}
BPTR deque(struct queue &q)
{
	if(q.front==-1)cout<<"queue is empty";
	else
	{
		BPTR t=q.elements[q.front];
		if(q.front==q.rear)
		{
			q.front=-1;q.rear=-1;
		}
		else q.front=(q.front+1)%q.size;
		return t;
	}
}
void levelprint(BPTR B)
{
	queue q;q.front=-1;q.rear=-1;q.size=30;
	BPTR L=new(bnode);L->data[0]=-1;
	enque(q,B);enque(q,L);
	while(q.front!=-1)
	{
		BPTR T=deque(q);cout<<"\t";
		if(T==L)
		{
			cout<<endl;if(q.front!=-1)enque(q,L);
		}
		else
		{
			for(int i=0;i<=T->count;i++)
			{
				if(T->ptr[i]!=NULL)enque(q,T->ptr[i]);
				cout<<T->data[i]<<" ";
			}
			if(T->ptr[T->count+1]!=NULL)enque(q,T->ptr[T->count+1]);
			for(int i=0;i<3-T->count;i++)cout<<"* ";
		}
	}
}
BPTR getptr(BPTR B,int el)
{
	if(B==NULL)return NULL;
	BPTR l=B;int i;
	for(i=0;i<=l->count;i++)
	{
		if(l->data[i]==el)return(l);
		if(l->data[i]>el)return getptr(B->ptr[i],el);
	}
	return getptr(B->ptr[i],el);
}
BPTR getparentptr(BPTR B,BPTR T)
{
		BPTR l=B;int i;
		if(l==T)return NULL;
	for(i=0;i<=l->count;i++)
	{
		if(l->data[i]>T->data[0])
		if(l->ptr[i]==T)return l;
		else return getparentptr(l->ptr[i],T);
	}
	if(l->ptr[i]==T)return l;
	else return getparentptr(l->ptr[i],T);
}
void insertandsort(BPTR &B,BPTR &T,int el,BPTR C);
int keyredistributionof(BPTR &B,BPTR &T)
{
	BPTR P=getparentptr(B,T);if(P==NULL)return 0;int i;
	for(i=P->count+1;i!=-1;i--)if(P->ptr[i]==T)break;
	if(i!=0&&P->ptr[i-1]->count<3)
	{
		P->ptr[i-1]->data[++P->ptr[i-1]->count]=P->data[i-1];
		P->ptr[i-1]->ptr[P->ptr[i-1]->count+1]=T->ptr[0];
		P->data[i-1]=T->data[0];
		for(int j=1;j<=T->count;j++)
		{
			T->ptr[j-1]=T->ptr[j];
			T->data[j-1]=T->data[j];
		}
		T->ptr[T->count]=T->ptr[T->count+1];T->count--;return 1;
	}
	else if(i!=P->count+1&&P->ptr[i+1]->count<3)
	{
		for(int j=P->ptr[i+1]->count;j>-1;j--)
		{
			P->ptr[i+1]->ptr[j+2]=P->ptr[i+1]->ptr[j+1];
			P->ptr[i+1]->data[j+1]=P->ptr[i+1]->data[j];
		}
		P->ptr[i+1]->ptr[1]=P->ptr[i+1]->ptr[0];
		P->ptr[i+1]->data[0]=P->data[i];
		P->data[i]=T->data[T->count];
		P->ptr[i+1]->ptr[0]=T->ptr[T->count+1];T->count--;P->ptr[i+1]->count++;return 1;
	}
	return 0;
}
void overflow(BPTR &B,BPTR &T)
{
	if(keyredistributionof(B,T)==1)return;
	BPTR P=getparentptr(B,T),temp;
	temp=new(bnode);temp->count=1;non++;
	for(int i=0;i<=5;i++)temp->ptr[i]=NULL;
	for(int i=3;i<=4;i++)
	{
		temp->data[i-3]=T->data[i];
		temp->ptr[i-3]=T->ptr[i];
	}
	temp->ptr[2]=T->ptr[5];T->count=1;
	insertandsort(B,P,T->data[2],temp);
}
void insertandsort(BPTR &B,BPTR &T,int el,BPTR C)
{
	if(T==NULL)
	{
			T=new(bnode);T->count=0;non++;
		for(int i=0;i<=5;i++)T->ptr[i]=NULL;T->data[0]=el;
		T->ptr[0]=B;T->ptr[1]=C;B=T;return;
	}
	int i=T->count;
		do
		{
			if(T->data[i]<el){T->data[i+1]=el;T->ptr[i+2]=C;break;}
			T->data[i+1]=T->data[i];T->ptr[i+2]=T->ptr[i+1];i--;
		}while(i>=0);
		if(i==-1)
		{
			T->data[0]=el;T->ptr[1]=C;
		}T->count++;
		if(T->count==4)overflow(B,T);
}
BPTR getexactlocation(BPTR B,int el)
{
	if(B->ptr[0]==NULL)return B;
	for(int i=0;i<=B->count;i++)
	{
		if(el<B->data[i])return getexactlocation(B->ptr[i],el);
	}
	return getexactlocation(B->ptr[B->count+1],el);
}
void add(BPTR &B,int el)
{
	if(B==NULL)
	{
		B=new(bnode);B->count=0;non++;
		for(int i=0;i<=5;i++)B->ptr[i]=NULL;B->data[0]=el;
	}
	else
	{
		BPTR C=NULL,T=getexactlocation(B,el);
		insertandsort(B,T,el,C);
	}
}

//CODE FOR DELETION.......................


int del(BPTR &B,int el,int t);
void underflow(BPTR &B,BPTR &T);
int keyredistributionuf(BPTR &B,BPTR &T)
{
	BPTR P=getparentptr(B,T);if(P==NULL)return 0;int i;
	for(i=P->count+1;i!=-1;i--)if(P->ptr[i]==T)break;
	if(i!=0&&P->ptr[i-1]!=NULL&&P->ptr[i-1]->count>1)
	{
		for(int j=T->count;j>=0;j--)
		{
			T->data[j+1]=T->data[j];
			T->ptr[j+2]=T->ptr[j+1];
		}
		T->ptr[1]=T->ptr[0];
		T->count++;
		T->data[0]=P->data[i-1];
		T->ptr[0]=P->ptr[i-1]->ptr[P->ptr[i-1]->count+1];
		P->data[i-1]=P->ptr[i-1]->data[P->ptr[i-1]->count--];
		return 1;
	}
	else if(i!=P->count+1&&P->ptr[i+1]!=NULL&&P->ptr[i+1]->count>1)
	{
		T->data[++T->count]=P->data[i];
		T->ptr[T->count+1]=P->ptr[i+1]->ptr[0];
		P->data[i]=P->ptr[i+1]->data[0];
		P->ptr[i+1]->count--;
		for(int j=0;j<=P->ptr[i+1]->count;j++)
		{
			P->ptr[i+1]->data[j]=P->ptr[i+1]->data[j+1];
			P->ptr[i+1]->ptr[j]=P->ptr[i+1]->ptr[j+1];
		}
		P->ptr[i+1]->ptr[P->ptr[i+1]->count+1]=P->ptr[i+1]->ptr[P->ptr[i+1]->count+2];
		return 1;
	}
	return 0;
}
void nodecombine(BPTR &B,BPTR &T)
{
	BPTR P=getparentptr(B,T);if(P==NULL)return;int i;
	for(i=P->count+1;i!=-1;i--)if(P->ptr[i]==T)break;
	if(i==0)
	{
		
		BPTR R=P->ptr[i+1],temp=R;
		T->ptr[2]=temp->ptr[0];
		for(int j=0;j<=temp->count;j++)
		{
			T->data[j+2]=temp->data[j];
			T->ptr[j+3]=temp->ptr[j+1];
		}
		T->count=3;T->data[1]=del(B,P->data[i],1);
		delete(temp);
	}
	else
	{
	BPTR L=P->ptr[i-1],temp=T;++L->count;
		L->ptr[L->count+1]=temp->ptr[0];
		for(int j=0;j<=temp->count;j++)
		{
			L->data[j+3]=temp->data[j];
			L->ptr[j+4]=temp->ptr[j+1];
		}
		L->count=3;L->data[2]=del(B,P->data[i-1],1);
		delete(temp);
	}
}
void underflow(BPTR &B,BPTR &T)
{
	if(B==T)
	{
		return;
	}
		if(keyredistributionuf(B,T)==1)return;
		nodecombine(B,T);
}
int del(BPTR &B,int el,int t)
{
	BPTR T=getptr(B,el);int k;
	for(int i=0;i<=T->count;i++)if(T->data[i]==el)k=i;
	if(T->ptr[0]==NULL)
	{
		for(int i=k;i<T->count;i++)T->data[i]=T->data[i+1];
		T->count--;
		if(T->count<1)underflow(B,T);
	}
	else
	{
		if(t==0)
		{
				BPTR C=T->ptr[k+1];
		while(C->ptr[0]!=NULL)C=C->ptr[0];
		if(C->count>1)
		{
			T->data[k]=del(B,C->data[0],0);return el;
		}
		C=T->ptr[k];
		while(C->ptr[0]!=NULL)C=C->ptr[C->count+1];
		if(C->count>1)
		{
			T->data[k]=del(B,C->data[C->count],0);return el;
		}
		T->data[k]=C->data[C->count];C->count--;
		underflow(B,C);
		}
		else
		{
			T->ptr[k+1]=NULL;
				for(int i=k;i<T->count;i++)
		{
			T->data[i]=T->data[i+1];
			T->ptr[i+1]=T->ptr[i+2];
		}
		T->count--;
	if(B==T&&B->count<0)
		{
			BPTR temp=B;B=T->ptr[0];delete(temp);return el;
		}
		if(T->count<1)underflow(B,T);
		}
	}
	return el;
}
int main()
{
	BPTR B=NULL;
	int n=0;
	cout<<"enter elements(-1 to stop)\n";
	while(1)
	{
		n++;if(n==26)break;if(getptr(B,n)!=NULL)continue;
		add(B,n);
		levelprint(B);
	}
	cout<<"enter elements to delete(-1 to stop)\n";
	while(1)
	{
		cin>>n;if(n==-1)break;if(getptr(B,n)==NULL){cout<<"not found";continue;}
		cout<<del(B,n,0)<<" is deleted\n";
		levelprint(B);
	}
	return 0;
}
