#include<iostream>
using namespace std;
struct avlnode
{
	struct avlnode *lchild;
	int data;
	struct avlnode *rchild;
};
typedef avlnode *AVLPTR;
void leftrotate(AVLPTR &T1)
{
	AVLPTR T3=T1,T2=T3->rchild;
	T1=T2;T3->rchild=T2->lchild;T2->lchild=T3;
}
void rightrotate(AVLPTR &T1)
{
	AVLPTR T3=T1,T2=T3->lchild;
	T1=T2;T3->lchild=T2->rchild;T2->rchild=T3;
}
int height(AVLPTR A)
{
	if(A==NULL)return -1;
	return(height(A->lchild)>height(A->rchild)?1+height(A->lchild):1+height(A->rchild));
}
int isbalanced(AVLPTR A)
{
	if(height(A->lchild)-height(A->rchild)>=-1&&height(A->lchild)-height(A->rchild)<=1)return 1;
	return (height(A->lchild)-height(A->rchild));
}
void adjust(AVLPTR &T,int n)
{
	AVLPTR l;
	if(n<0)
	{
		l=T->rchild;
		if(height(l->lchild)>height(l->rchild))
		rightrotate(T->rchild);
		leftrotate(T);
	}
	else
	{
		l=T->lchild;
		if(height(l->lchild)<height(l->rchild))
		leftrotate(T->lchild);
		rightrotate(T);	
	}
}
void insert(AVLPTR &A,AVLPTR &T,int n,int &k)
{
	if(T==NULL)
	{
		T=new(avlnode);T->data=n;T->lchild=NULL;T->rchild=NULL;
	}
	else
	{
		if(T->data>n)
		{
			insert(A,T->lchild,n,k);
			if(isbalanced(T)!=1&&k==0)
		    {adjust(T,isbalanced(T));k=1;}
		}
		else 
		{
			insert(A,T->rchild,n,k);
			if(isbalanced(T)!=1&&k==0)
		    {adjust(T,isbalanced(T));k=1;}
		}
	}
}
void printldr(AVLPTR A)
{
	if(A!=NULL)
	{
		printldr(A->lchild);
		cout<<A->data<<"  ";
		printldr(A->rchild);
	}
}
int main()
{
	AVLPTR A;A=NULL;
	int n,k;
	cout<<"enter values to keep in tree(-1 to stop):\n";
	while(1)
	{
		cin>>n;
		if(n==-1)break;k=0;
		insert(A,A,n,k);
	}
	printldr(A);
	return 0;
}
