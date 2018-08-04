#include<iostream>
using namespace std;
typedef
struct BSTnode{
	struct BSTnode *lc;
	int data;
	struct BSTnode *rc;
}
*BSTptr;

void insert(BSTptr &T,int d )
{
	while(T!=NULL)
	{
	    if(T->data>d)
	        {
	        	if(T->lc!=NULL)
	          	   T=T->lc;
	          	else break;
	        }
	    else if(T->data<d)
	        {
	        	if(T->rc!=NULL)
	         	    T=T->rc;
				 else break;	
	        }

    }
    if(T->data>d)
		{
			T->lc=new(BSTnode);
			T=T->lc;
		}
    else
		{
			T->rc=new(BSTnode);
			T=T->rc;
		}
	T->data=d;
	T->lc=NULL;
	T->rc=NULL;
}

void creat(BSTptr &T)
{
	int d;BSTptr t;
	cout<<"enter root element:(-1 to stop)\n";
	cin>>d;
	if(d!=-1)
	{
	   T=new(struct BSTnode);
	   T->data=d;
	   T->lc=NULL;
	   T->rc=NULL;
    }
    while(1)
    {  t=T;
    		cout<<"enter element to be inserted :(-1 to stop)\n";
			cin>>d;
    		if(d!=-1)
    		{
			   insert(t,d);
			}
			else 
		    {
			    break;
		    }
	}
}

void del(BSTptr &T)
 {    int k;BSTptr p,t,t1;
      t=T;t1=T;
  	  cout<<"enter element\n";
	  cin>>k;
	  while(t!=NULL)
	  {
	      if(t->data==k)
		        {
				  break;}
		else if(t->data>k)
		
		       {
				 t=t->lc;}
	    else 	
		    {
			  t=t->rc;}
	  }
	  
	  if(t->lc==NULL && t->rc==NULL)
	 	   {  
			  t=NULL; 
	 	      delete(t);
	       }
	 else
	 	   {
			 p=t;t1=t;t1=t1->rc;
			 while(t1->rc!=NULL)
	    		 {     t1=t1->lc;
	  				   t=t->rc; 
   				 }
				 p->data=t1->data;
				   t->rc=NULL; 
			      delete(t1);
			      
		   }
 }
void print (BSTptr T)
{
	if(T!=NULL)
	{
      	print(T->lc);
		cout<<T->data<<" ";
	}
    else return;
    print(T->rc);
}

int main()
{ int p,s;
	BSTptr T;
	T=NULL;
	creat(T);
	del(T);
	cout<<"after deletion\n"<<endl;
	print(T);
	return 0;
	}

