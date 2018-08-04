#include<iostream>
using namespace std;
typedef
struct BSTnode{
	struct BSTnode *lc;
	int data;
	struct BSTnode *rc;
}
*BSTptr;

void addend(BSTptr &T,int d);

void creat(BSTptr &T)
{
	int d;	
			cout<<"enter root element (1 to stop)\n";
			cin>>d;
			if(d!=1)
		{T=new(BSTnode);
		T->lc=NULL;
		T->rc=NULL;
		 T->data=d;
	    addend(T,d);
	    }
}
		
void addend(BSTptr &T,int d)
  { 
    BSTptr t=T,t1=T;int k;
                   cout<<"enter left side (1 to stop) "<<d<<endl;
	               cin>>k;
				if(k!=1){
					 t->lc=new(BSTnode);
				              t=t->lc;
			                   t->data=k;t->lc=NULL;
							   t->rc=NULL;
		                      addend(t,k);
				       }
		           cout<<"enter right side (1 to stop) "<<d<<endl;
	               cin>>k;
	        	if(k==1){return;
				        }
			       t1->rc=new(BSTnode);
			       t1=t1->rc;
			       t1->data=k;t1->lc=NULL;t1->rc=NULL;
		   	       addend(t1,k);
		   	       
  }
  void printarray(int a[],int len)
  {
  	for(int i=0;i<len;i++)
		  cout<<a[i]<<" ";
  }
  void print(BSTptr t,int a[],int i)
  {
  	  
  	  
  	  a[i++]=t->data;

  	if(t->lc==NULL && t->rc==NULL)
  		{   
		  printarray(a,i);cout<<endl;
		}
	else
		{
		print(t->lc,a,i);	
		print(t->rc,a,i);
		}
		
	  if(t==NULL)
  	  return;	
	
  }
  void printpaths(BSTptr T)
  {
  	int a[100];int i=0;
  	print(T,a,i);
  }
int main()
{
	
	BSTptr  T ;T=NULL;
	creat(T);
	cout<<"printing all paths\n";
	printpaths(T);
	return 0;
}
