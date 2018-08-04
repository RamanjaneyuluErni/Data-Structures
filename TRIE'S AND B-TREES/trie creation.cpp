#include<iostream>
#include<cstring>
using namespace std;
int n,non=0;
typedef
struct bnode
{
	int tag;
	union select
	{
	   struct bnode **ptr;//tag=0
	   char a[10];//tag=1
	}u;
}*bptr;
int getvalue(char A[],char c)
{
   for(int i=0;i<strlen(A);i++) { if(A[i]==c) return i;}
}
void insert(bptr &T,char A[],char B[])
{
	int i=0;bptr t=T;
	while(i<strlen(B) && t->u.ptr[getvalue(A,B[i])]!=NULL && t->u.ptr[getvalue(A,B[i])]->tag==0)
	{
		t=t->u.ptr[getvalue(A,B[i])];i++;
	}
	if(i==strlen(B))
	{
		t->u.ptr[n]=new bnode;non++;
		t->u.ptr[n]->tag=1;
		strcpy(t->u.ptr[n]->u.a,B);
	}
	else if(t->u.ptr[getvalue(A,B[i])]==NULL)
	{
		t->u.ptr[getvalue(A,B[i])]=new bnode;non++;
		t=t->u.ptr[getvalue(A,B[i])];t->tag=1;
		strcpy(t->u.a,B);
	}
	else
	{
		char temp[10];bptr tempptr=t->u.ptr[getvalue(A,B[i])];
		strcpy(temp,tempptr->u.a);
		int j=0;bptr l=T;
		while(1)
			{
				if(l==t)break;
				l=l->u.ptr[getvalue(A,temp[j])];j++;
			}
		t->u.ptr[getvalue(A,B[i])]=new bnode;non++;
		t=t->u.ptr[getvalue(A,B[i])];t->tag=0;
		t->u.ptr= new bptr[n+1];
		for(int k=0;k<n+1;k++) t->u.ptr[k]=NULL;
		t->u.ptr[getvalue(A,temp[j+1])]=tempptr;
		insert(T,A,B);
	}
}
void create(bptr &T,char A[],char B[])
{
	if(T==NULL)
	{
	  T=new bnode;T->tag=0;non++;
	  T->u.ptr=new bptr[n+1];	
	  for(int i=0;i<n+1;i++) T->u.ptr[i]=NULL;
	  T->u.ptr[getvalue(A,B[0])]=new bnode;non++;
	  T->u.ptr[getvalue(A,B[0])]->tag=1;
	  strcpy(T->u.ptr[getvalue(A,B[0])]->u.a,B);
	  return;
	}
    insert(T,A,B);
}
void print(bptr &T)
{
	   if(T==NULL) return;
	   bptr t=T;
	   for(int i=0;i<n+1;i++)
	   {
	   	  if(t->tag==1) 
			 {
			 	cout<<t->u.a<<" ";return;
			 }
		  else print(t->u.ptr[i]);
	   }
     
}
int main()
{
	bptr T=NULL;char A[10],B[10],c;
	cout<<"no of alphabets:";cin>>n;
	cout<<"enter alphabets do u want\n";
	for(int i=0;i<n;i++) cin>>A[i];
	while(1)
	{   
		cout<<"do u want to continue?(y/n)";cin>>c;
		if(c=='n')break;
		cout<<"enter name : ";cin>>B;
		create(T,A,B);
		cout<<"nodes="<<non<<endl;
		print(T);cout<<endl;
	}
	cout<<"printing \n";
	print(T);
	return 0;
}
