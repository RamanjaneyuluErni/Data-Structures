#include<iostream>
#include<cstring>
using namespace std;
int n,non=0,count;
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
bptr search(bptr &T,char A[],char B[],int i)
{
    bptr t=T;
    int x=getvalue(A,B[i]);
    if(i==strlen(B))
    {
    	if(t->u.ptr[n]!=NULL && strcmp(B,t->u.ptr[n]->u.a)==0) return t->u.ptr[n];
    	if(t->u.ptr[n]==NULL || strcmp(B,t->u.ptr[n]->u.a)!=0) return NULL;
	}
    else if(t->u.ptr[x]==NULL || t->u.ptr[x]->tag==1 && strcmp(B,t->u.ptr[x]->u.a)!=0) return NULL;
	else if(t->u.ptr[x]->tag==1 && strcmp(B,t->u.ptr[x]->u.a)==0) return t->u.ptr[x];
	else return search(t->u.ptr[x],A,B,i+1);
}
bptr getparentptr(bptr &T,bptr &P,char A[],char B[],int i)
{
	if(T==P) return NULL;
	bptr t=T;
	int x=getvalue(A,B[i]);
	if(t->u.ptr[x]==P || t->u.ptr[n]==P) return t;
	else return getparentptr(t->u.ptr[x],P,A,B,i+1);
}
int countfun(bptr &P,int &bp)
{
	  int count=0;
      for(int i=0;i<n+1;i++)
	  {
		if(P->u.ptr[i]!=NULL) 
		{
			if(P->u.ptr[i]->tag==0) { bp++;}  
			count++;
		}
		
	  }
	  return count;
}
void repair(bptr &T,char A[],char B[],bptr &P)
{
	int bp=0,count=countfun(P,bp);char buffer[10];
	bptr temp,temp1;
	if(count==0 && T==P) //incase if root has only one child;
	{
	  cout<<"now trie is NULL";non--;
	  T=NULL;return;
	}
	if(count==0) //case :other than root has only one child;
	{
		temp=getparentptr(T,P,A,B,0);
		for(int i=0;i<n+1;i++)
		{
			if(temp->u.ptr[i]==P) temp->u.ptr[i]=NULL;
		} non--;
		repair(T,A,B,temp);
	}
	else if(count>=1 && bp>=1) return; 
	else if(count==1 && bp==0 && T!=P)
	{
		temp=getparentptr(T,P,A,B,0);
		for(int i=0;i<n+1;i++)
	    {
		  if(P->u.ptr[i]!=NULL) 
		  {
		  	temp1=P->u.ptr[i];P->u.ptr[i]=NULL;break;
		  }
		}
		for(int i=0;i<n+1;i++)
		{
			if(temp->u.ptr[i]==P)
			{
				temp->u.ptr[i]=NULL;non--;temp->u.ptr[i]=temp1;
			}
		}
		repair(T,A,B,temp);
	} 
}
void delet(bptr &T,char A[],char B[],bptr &t)
{
	bptr P=getparentptr(T,t,A,B,0);
	for(int i=0;i<n+1;i++)
	{
	   if(P->u.ptr[i]==t) 
		{
		   P->u.ptr[i]=NULL;non--;break;
		}
	}
	repair(T,A,B,P);
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
		cout<<"enter string : ";cin>>B;
		create(T,A,B);
		cout<<"nodes="<<non<<endl;
		print(T);cout<<endl;
	}
	cout<<"printing \n";
	print(T);cout<<endl;
	while(1)
	{
		cout<<"do u want to continue deletion?(y/n)";cin>>c;
		if(c=='n') break;
		cout<<"enter string to delete:";cin>>B;
		bptr t=search(T,A,B,0); 
		if(t==NULL) cout<<"string not found\n";
		else 
		{
			cout<<"string found:"<<t->u.a<<endl;
			delet(T,A,B,t);
			cout<<"after deleting string : "<<t->u.a<<endl;
			print(T);cout<<endl;
			cout<<"remaining nodes="<<non<<endl;
		}
		
	}
	return 0;
}
