#include<iostream>
#include<cstring>
using namespace std;
int n,non=0;
typedef
struct cnode
{
	int tag;
	int count;
	union select
	{
	   struct cnode **ptr;//tag=0
	   char a[10];//tag=1
	}u;
}*cptr;
int getvalue(char A[],char c)
{
   for(int i=0;i<strlen(A);i++) { if(A[i]==c) return i;}
}
void insert(cptr &T,char A[],char B[])
{
	
}
void create(cptr &T,char A[],char B[])
{
	if(T==NULL)
	{
	  T=new cnode;T->tag=0;non++;
	  T->u.ptr=new cptr[n+1];T->count=1;
	  for(int i=0;i<n+1;i++) T->u.ptr[i]=NULL;
	  T->u.ptr[getvalue(A,B[0])]=new cnode;non++;
	  T->u.ptr[getvalue(A,B[0])]->tag=1;
	  strcpy(T->u.ptr[getvalue(A,B[0])]->u.a,B);
	  return;
	}
    insert(T,A,B);
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
}
