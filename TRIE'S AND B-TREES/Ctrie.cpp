#include<iostream>
#include<cstring>
using namespace std;
int n,count;char *A;
typedef
struct ctnode
{
	int tag;int com;
	union pointer
	{
		char ch[10];
		ctnode **ptr;
	}u;
}*CPTR;
int getindex(char c)
{
	for(int i=0;i<n;i++)if(A[i]==c)return i;
	return -1;
}
void print(CPTR T)
{
	if(T==NULL)return;
	if(T->tag==0){cout<<T->u.ch<<" ";return;}
	for(int i=0;i<n+1;i++)print(T->u.ptr[i]);
}
int find(CPTR T,char str[])
{
	if(T==NULL)return -1;
	if(T->tag==0)if(strcmp(T->u.ch,str)==0)return 1;else return -1;
	int i=T->com;
	if(i>=strlen(str))return find(T->u.ptr[n],str);
	return find(T->u.ptr[getindex(str[i])],str);
}
//int find(CPTR T,char str[])
//{
//	if(T==NULL||(T->tag==0&&strcmp(T->u.ch,str)!=0))return 0;
//	if(T->tag==0)return 1;
//	for(int i=0;i<n+1;i++)if(find(T->u.ptr[i],str)==1)return 1;
//	return 0;
//}
CPTR getastring(CPTR T)
{
	if(T->tag==0)return T;
	for(int i=0;i<n+1;i++)if(T->u.ptr[i]!=NULL)return getastring(T->u.ptr[i]);
}
int noofcharacterssame(char ch1[],char ch2[])
{
	int i=0;
	while(i<strlen(ch1)&&i<strlen(ch2)&&ch1[i]==ch2[i])i++;
	return i;
}
CPTR getparentptr(CPTR T,CPTR C,char str[])
{
	if(T==C)return NULL;int i=T->com;
	if(T->u.ptr[getindex(str[i])]==C||T->u.ptr[n]==C)return T;
	return getparentptr(T->u.ptr[getindex(str[i])],C,str);
}
void insert(CPTR &T,char str[])
{
	if(T==NULL)
	{
		T=new ctnode;count++;T->tag=0;
		strcpy(T->u.ch,str);
	}
	else
	{
		CPTR L=T;int i=0,k=0;
		while(i<strlen(str)&&L->u.ptr[getindex(str[i])]!=NULL&&L->u.ptr[getindex(str[i])]->tag==1)
		{
			k=L->com;
			if(noofcharacterssame(getastring(L)->u.ch,str)<L->com)break;
			L=L->u.ptr[getindex(str[i])];
			i=L->com;
		}
		if(noofcharacterssame(getastring(L)->u.ch,str)<L->com)
		{
			CPTR temp=L,P=getparentptr(T,L,str);for(i=0;i<n+1;i++)if(P->u.ptr[i]==L)break;
			P->u.ptr[i]=new ctnode;
		L=P->u.ptr[i];
			count++;L->tag=1;L->u.ptr=new ctnode *[n+1];
			for(i=0;i<n+1;i++)L->u.ptr[i]=NULL;char string[10];strcpy(string,getastring(temp)->u.ch);
			L->com=noofcharacterssame(string,str);
			if(L->com<strlen(string))L->u.ptr[getindex(string[L->com])]=temp;
			else L->u.ptr[n]=temp;
			if(L->com<strlen(str))insert(L->u.ptr[getindex(str[L->com])],str);
			else insert(L->u.ptr[n],str);return;
		}
		if(i==strlen(str))
		{
			insert(L->u.ptr[n],str);
			return;
		}
		if(L->u.ptr[getindex(str[i])]==NULL)
		{
			insert(L->u.ptr[getindex(str[i])],str);
			return;
		}
			CPTR temp=L->u.ptr[getindex(str[i])];
			L->u.ptr[getindex(str[i])]=new ctnode;count++;L=L->u.ptr[getindex(str[i])];L->u.ptr=new ctnode *[n+1];L->tag=1;
			for(int j=0;j<n+1;j++)L->u.ptr[j]=NULL;L->com=noofcharacterssame(temp->u.ch,str);
			if(L->com<strlen(temp->u.ch))L->u.ptr[getindex(temp->u.ch[L->com])]=temp;
			else L->u.ptr[n]=temp;
			if(L->com<strlen(str))insert(L->u.ptr[getindex(str[L->com])],str);
			else insert(L->u.ptr[n],str);
	}
}
int main()
{
	CPTR T=NULL;int i,choice;char str[10];
	cout<<"enter n:\n";
	cin>>n;A=new char[n];
	cout<<"enter alphabets:\n";
	for(i=0;i<n;i++)cin>>A[i];
	cout<<"enter a string to insert:\n";
	cin>>str;
	T=new ctnode;count++;T->com=0;T->tag=1;T->u.ptr=new ctnode *[n+1];
	for(i=0;i<n+1;i++)T->u.ptr[i]=NULL;insert(T->u.ptr[getindex(str[0])],str);
	print(T);cout<<"\nno.of nodes= "<<count;
	while(1)
	{
		cout<<"\nenter 1 for insert 2 for search 3 for exit:\n";
		cin>>choice;if(choice!=1&&choice!=2)break;
		switch(choice)
		{
			case 1:cout<<"enter string to insert:\n";
					cin>>str;if(find(T,str)==1)continue;insert(T,str);print(T);cout<<"\nno.of nodes= "<<count;
					break;
			case 2:cout<<"enter string to search:\n";
					cin>>str;if(find(T,str)==1)cout<<"found\n";else cout<<"not found\n";
		}
	}
	return 0;
}
