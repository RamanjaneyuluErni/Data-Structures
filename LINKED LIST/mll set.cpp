#include<iostream>
using namespace std;
typedef
struct mlnode{
	int tag;
	union  u{
	          char data;
              struct mlnode *bnext;
              
			 }a;
	struct mlnode *next;
}*dptr;
void addptr(dptr &l);
void creat(dptr &l);
void addend(dptr &l,char d)
{
  dptr t;
  if(l==NULL)
     {
	   l=new(struct mlnode);
       l->a.data=d;
       l->next=NULL;
       l->tag=1;
	}
	else
	{ t=l;
	 while(t->next!=NULL)
     	{
     		t=t->next;
     	}
	   t->next=new(struct mlnode);
	   t=t->next;
	     t->tag=1;
	   t->a.data=d;
	   t->next=NULL;
	}
}
void addptr(dptr &l)
{
  dptr t;
  if(l==NULL)
     {
	   l=new(struct mlnode);
       l->a.bnext=NULL;
       l->next=NULL;
       l->tag=2;
       creat(l->a.bnext)  ; 
	}
	else
	{ t=l;
	   while(t->next!=NULL)
	   {t=t->next;
	   }
	   t->next=new(struct mlnode);
	   t=t->next;
	   t->tag=2;
	   t->a.bnext=NULL;
	   t->next=NULL; 
	   creat(t->a.bnext);
	}
	
}
void creat(dptr &l)
{
   char d;int n;
     do
       {
		    cout<<"1.char\n ";
		    cout<<"2.branch pointer\n 0.to stop\n";
		    cin>>n;
		    if(n==1)
		    {
			   cout<<"enter char\n";
			   cin>>d;
		       addend(l,d); 
			 }
		  else if(n==2)
		     {
			  cout<<"created a branch pointer\n";
		      addptr(l);
		    }
		  
		}
        while(n==1||n==2);
        
 }
 
  void print(dptr &l)
  {
      dptr t=l;
	  cout<<"( ";
      while(t!=NULL)
     {  
		    if(t->tag==1)
	      {
	   	     cout<<t->a.data<<" ";
		  }
	   	  else if(t->tag==2)
	      {
	          print (t->a.bnext);
		  }
		   
		   t=t->next;
     }
   cout<<") ";
  }
 void printarray(char a[],int len)
 {
 	for(int i=0;i<len;i++)
 	{
 		cout<<a[i]<<" ";
	 }
	 cout<<endl;
 }
void printpaths(dptr &t,char a[],int i)
{ 
  dptr l=t;
	 if(l==NULL)
	  return;
	 else
	 {
	
		  if(l->tag==1)
	     {
		   a[i++]=l->a.data;
	     }
		  if(l->tag==2)
		 { 
		 	  printpaths(l->a.bnext,a,i);
		 }
		 if(l->next==NULL)
	 	 {
	 		  printarray(a,i);
		 }
	 	
	 }
	 
	
}
int main()
{
  dptr l;l=NULL;
  creat(l);
  print(l);
  char a[20];int i=0;
  printpaths(l,a,i);
  return 0;
}
