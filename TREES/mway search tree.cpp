#include <iostream>
#include<cstring>
using namespace std;
typedef
struct MSTnode{
            
                int count; 
				int *key;
                struct MSTnode **ptr;
                
              }*mstptr;
              
void create(mstptr &t,int d,int m)
{
	if(t==NULL )
	{  
		t=new MSTnode;t->key=new int[m];t->ptr=new mstptr[m+1];
	    t->count=0;t->key[0]=d;
	    	for(int i=0;i<=m;i++)t->ptr[i]=NULL;
	}
	else if(t->count<m-1)
		{
			int i=t->count;
	       do
	       {
	       	 if(t->key[i]<d)
	       	  {
	       	    t->key[i+1]=d;return;
	       	 }
			  t->key[i+1]=t->key[i];
		   }while(--i>=0);
		   if(i==-1)t->key[0]=d;
		   t->count++;
	   	}
	else
	{
     	  for(int i=0;i<=t->count;i++)
		   	{
		   	   if(t->key[i]>d) 
				  {
				     create(t->ptr[i],d,m);return;
				  }
			}
			create(t->ptr[t->count+1],d,m);
	}
}
void print(mstptr &t)
{
	if(t==NULL) return;
	for(int i=0;i<=t->count;i++)
	{
	     print(t->ptr[i]);
	  	 cout<<t->key[i]<<" ";	
	}
	print(t->ptr[t->count+1]);
}
int find(mstptr &t,int d,int m)
{
	if(t==NULL)return 0;
	for(int i=0;i<=t->count;i++)
	{
		if(t->key[i]>d)
		{
			find(t->ptr[i],d,m);
		}
		else if(t->key[i]==d) return 1;
	}
	find(t->ptr[t->count+1],d,m);
}
int main()
{
	mstptr t;
	t=NULL;
	int d,m;
	cout<<"no of keys\n";
	cin>>m;
	while(1)
	
	{
	   cout<<"enter data(-1 to stop)\n";
	   cin>>d;
	   if(d!=-1)
	    {
		    create(t,d,m);
		}
		  else break;
	}
	cout<<"printing of mway search tree\n";
	print(t);
	while(1)
	{
     cout<<"\nenter element to find(-1 to stop)\n";
     cin>>d;
	 if(d==-1)break;
	if(find(t,d,m)==1)
	cout<<"found\n";
	else
	cout<<"no\n";
		}
	return 0;
}
              

