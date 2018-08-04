#include<iostream>
#include<queue>
using namespace std;
typedef
struct bnode
{
	int count;
	int data[5];
	int tag;
	union pointer
	{
		bnode *ptr[6];
		bnode *lptr;
	}u;
}*BPTR;
void printinorder(BPTR B)
{
	if(B==NULL)return;
	if(B->tag==0)
	{
		for(int i=0;i<=B->count;i++)
		cout<<B->data[i]<<"  ";return;
	}
	for(int i=0;i<=B->count;i++)
	{
		printinorder(B->u.ptr[i]);
		cout<<B->data[i]<<"  ";
	}
	printinorder(B->u.ptr[B->count+1]);
}
void printleaf(BPTR B)
{
	BPTR T=B;
	while(T->tag==1)
	T=T->u.ptr[0];
	while(T!=NULL)
	{
		for(int i=0;i<=T->count;i++)cout<<T->data[i]<<" ";
		T=T->u.lptr;
	}
}
void levelprint(BPTR B)
{
	queue<BPTR>q;
	BPTR L=new(bnode);L->data[0]=-1;
	q.push(B);q.push(L);
	while(q.size()!=0)
	{
		BPTR T=q.front();q.pop();cout<<"\t";
		if(T==L)
		{
			cout<<endl;if(q.size()!=0)q.push(L);
		}
		else
		{
			for(int i=0;i<=T->count;i++)
			{
				if(T->tag==1&&T->u.ptr[i]!=NULL)q.push(T->u.ptr[i]);
				cout<<T->data[i]<<" ";
			}
			if(T->tag==1&&T->u.ptr[T->count+1]!=NULL)q.push(T->u.ptr[T->count+1]);
			for(int i=0;i<3-T->count;i++)cout<<"_ ";
		}
	}
}
BPTR getptr(BPTR B,int el)
{
	if(B==NULL)return NULL;
	BPTR l=B;int i;
	for(i=0;i<=l->count;i++)
	{
		if(l->data[i]==el&&l->tag==0)return(l);
		if(l->data[i]>el&&l->tag==1)return getptr(B->u.ptr[i],el);
	}
	if(B->tag==0)return NULL;
	return getptr(B->u.ptr[i],el);
}
BPTR getparentptr(BPTR B,BPTR T)
{
		BPTR l=B;int i;
		if(l==T)return NULL;
	for(i=0;i<=l->count;i++)
		if(l->data[i]>T->data[0])
		if(l->u.ptr[i]==T)return l;
		else return getparentptr(l->u.ptr[i],T);
	if(l->u.ptr[i]==T)return l;
	else return getparentptr(l->u.ptr[i],T);
}
void insertandsort(BPTR &B,BPTR &T,int el,BPTR &C);
void overflow(BPTR &B,BPTR &T)
{
	BPTR P=getparentptr(B,T),temp;
	temp=new(bnode);
	if(T->tag==0)
	{
		temp->count=2;temp->tag=0;
	    temp->u.lptr=NULL;
	    for(int i=2;i<=4;i++)
	    {
		temp->data[i-2]=T->data[i];
	    }
	    T->count=1;
	    temp->u.lptr=T->u.lptr;
	    T->u.lptr=temp;
	}
	else
	{
	   temp->count=1;temp->tag=1;
	   for(int i=0;i<=5;i++)temp->u.ptr[i]=NULL;
	   for(int i=3;i<=4;i++)
	   {
		 temp->data[i-3]=T->data[i];
		 temp->u.ptr[i-3]=T->u.ptr[i];
	   }
	   temp->u.ptr[2]=T->u.ptr[5];T->count=1;
	}
	insertandsort(B,P,T->data[2],temp);
}
void insertandsort(BPTR &B,BPTR &T,int el,BPTR &C)
{
	if(T==NULL)
	{
		T=new(bnode);T->count=0;T->tag=1;
		for(int i=0;i<=5;i++)T->u.ptr[i]=NULL;T->data[0]=el;
		T->u.ptr[0]=B;T->u.ptr[1]=C;B=T;return;
	}
	int i=T->count;
		do
		{
			if(T->data[i]<el){T->data[i+1]=el;if(T->tag==1)T->u.ptr[i+2]=C;break;}
			T->data[i+1]=T->data[i];if(T->tag==1)T->u.ptr[i+2]=T->u.ptr[i+1];i--;
		}while(i>=0);
		if(i==-1)
		{
			T->data[0]=el;if(T->tag==1)T->u.ptr[1]=C;
		}T->count++;
		if(T->count==4)overflow(B,T);
}
BPTR getexactlocation(BPTR B,int el)
{
	if(B->tag==0)return B;
	for(int i=0;i<=B->count;i++)
	{
		if(el<B->data[i])return getexactlocation(B->u.ptr[i],el);
	}
	return getexactlocation(B->u.ptr[B->count+1],el);
}
void add(BPTR &B,int el)
{
	if(B==NULL)
	{
		B=new(bnode);B->count=0;B->tag=0;B->u.lptr=NULL;B->data[0]=el;
	}
	else
	{
		BPTR C=NULL,T=getexactlocation(B,el);
		insertandsort(B,T,el,C);
	}
}

//CODE FOR DELETION....
int del(BPTR &B,int el,int t);
void nodecombine(BPTR &B,BPTR &T)
{
	BPTR P=getparentptr(B,T);if(P==NULL)return;int i;
	for(i=P->count+1;i!=-1;i--)if(P->u.ptr[i]==T)break;
	if(i==0)
	{	
		BPTR R=P->u.ptr[i+1],temp=R;
		if(T->tag==0)
		{
			for(int j=0;j<=temp->count;j++)T->data[j+1]=temp->data[j];
			T->count=2;T->data[1]=del(B,P->data[i],1);
		}
		else
		{
			T->u.ptr[2]=temp->u.ptr[0];
			for(int j=0;j<=temp->count;j++)
			{
				T->data[j+2]=temp->data[j];T->u.ptr[j+3]=temp->u.ptr[j+1];
			}
			T->count=3;T->data[1]=del(B,P->data[i],1);
		}
		if(T->tag==0)T->u.lptr=temp->u.lptr;
		else T->u.ptr[5]=temp->u.ptr[5];
		delete(temp);
	}
	else
	{
		BPTR L=P->u.ptr[i-1],temp=T;
		if(L->tag==0)
		{
			for(int j=0;j<=temp->count;j++)L->data[j+2]=temp->data[j];
			L->count=2;L->data[2]=del(B,P->data[i-1],1);
		}
		else
		{
			++L->count;
			L->u.ptr[L->count+1]=temp->u.ptr[0];
			for(int j=0;j<=temp->count;j++)
			{
				L->data[j+3]=temp->data[j];L->u.ptr[j+4]=temp->u.ptr[j+1];
			}
			L->count=3;L->data[2]=del(B,P->data[i-1],1);
		}
		if(L->tag==0)L->u.lptr=temp->u.lptr;
		else T->u.ptr[5]=temp->u.ptr[5];
		delete(temp);
	}
}
int keyredistributionuf(BPTR &B,BPTR &T)
{
	BPTR P=getparentptr(B,T);if(P==NULL)return 0;int i;
	for(i=P->count+1;i!=-1;i--)if(P->u.ptr[i]==T)break;
	if(i!=0&&P->u.ptr[i-1]!=NULL&&P->u.ptr[i-1]->count>1)
	{
		for(int j=T->count;j>=0;j--)
		{
			T->data[j+1]=T->data[j];
			if(T->tag==1)T->u.ptr[j+2]=T->u.ptr[j+1];
		}
		if(T->tag==1)T->u.ptr[1]=T->u.ptr[0];BPTR L=P->u.ptr[i-1];
		if(T->tag==1)T->u.ptr[0]=L->u.ptr[L->count+1];
		T->count++;
		if(L->tag==0)
		{
			T->data[0]=L->data[L->count];
			P->data[i-1]=T->data[0];L->count--;return 1;
		}
		T->data[0]=P->data[i-1];
		P->data[i-1]=L->data[L->count];
		L->count--;
		return 1;
	}
	else if(i!=P->count+1&&P->u.ptr[i+1]!=NULL&&P->u.ptr[i+1]->count>1)
	{
		T->data[++T->count]=P->data[i];BPTR R=P->u.ptr[i+1];
		if(T->tag==1)T->u.ptr[T->count+1]=R->u.ptr[0];
		P->data[i]=R->data[0];
		R->count--;
		if(R->tag==0)
		{
			P->data[i]=R->data[1];
		}
		for(int j=0;j<=R->count;j++)
		{
			R->data[j]=R->data[j+1];
			if(R->tag==1)R->u.ptr[j]=R->u.ptr[j+1];
		}
		if(R->tag==1)R->u.ptr[R->count+1]=R->u.ptr[R->count+2];
		return 1;
	}
	return 0; 
}
void underflow(BPTR &B,BPTR &T)
{
	if(B==T)return;
	if(keyredistributionuf(B,T)==1)return;
	nodecombine(B,T);
}
int del(BPTR &B,int el,int t)
{
	BPTR T=getptr(B,el);
	if(t==1)
	{
		BPTR P=T;int j;
		while(1)
		{
			P=getparentptr(B,P);if(P==NULL)break;
			for(j=0;j<=P->count;j++)if(P->data[j]==el)break;
			if(j<=P->count)break;
		}T=P;
		for(j=0;j<=T->count;j++)if(T->data[j]==el)break;
		T->u.ptr[j+1]=NULL;
		for(int i=j;i<T->count;i++)
		{
		T->data[i]=T->data[i+1];
		if(T->tag==1)T->u.ptr[i+1]=T->u.ptr[i+2];
		}T->count--;
		if(B==T&&B->count<0)
		{
			BPTR temp=B;B=T->u.ptr[0];delete(temp);return el;
		}
		if(T->count<1)underflow(B,T);
		return el;
	}
	int i;
	for(i=0;i<=T->count;i++)if(T->data[i]==el)break;
	if(i!=0)
	{
		for(int j=i;j<T->count;j++)T->data[i]=T->data[i+1];
		T->count--;
	}
	else
	{
		BPTR P=T;int j;
		while(1)
		{
			P=getparentptr(B,P);if(P==NULL)break;
			for(j=0;j<=P->count;j++)if(P->data[j]==el)break;
			if(j<=P->count)break;
		}
		if(P!=NULL)P->data[j]=T->data[1];
		for(j=0;j<T->count;j++)T->data[j]=T->data[j+1];
		T->count--;
	}
	if(T->count==0)underflow(B,T);
	return el;
}
int main()
{
	BPTR B=NULL;
	int n;
	cout<<"enter elements(-1 to stop)\n";
	while(1)
	{
		cin>>n;if(n==-1)break;
		add(B,n);
		levelprint(B);
	}
printleaf(B);
cout<<"enter elements to delete(-1 to stop)\n";
	while(1)
	{
		cin>>n;if(n==-1)break;if(getptr(B,n)==NULL){cout<<"not found";continue;}
		cout<<del(B,n,0)<<" is deleted\n";
		levelprint(B);
	}
	printleaf(B);
	return 0;
}
