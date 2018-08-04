#include<iostream>
using namespace std;
typedef
struct BSTnode{
	struct BSTnode *lc;
	int data;
	struct BSTnode *rc;
}
*BSTptr;

struct stack{
	int size;
	BSTptr element[20];
	int top;
}s;

void push(struct stack &s,BSTptr x)
   {  
       if(s.top==s.size-1)
           cout<<"stack is full\n";
        else
       s.element[++s.top]=x;
   }
   
BSTptr pop(struct stack &s)
   {  
        if(s.top==-1)
          cout<<"stach is empty\n";
        else
        return(s.element[s.top--]);
   }

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
			              t->data=k;t->lc=NULL;t->rc=NULL;
		                  addend(t,k);
				       }
		          cout<<"enter right side (1 to stop) "<<d<<endl;
	               cin>>k;
	        	if(k==1){return;}
			       t1->rc=new(BSTnode);
			       t1=t1->rc;
			       t1->data=k;t1->lc=NULL;t1->rc=NULL;
		   	       addend(t1,k);
		   	       
}

void printRLD(BSTptr &t)
{  s.top=-1;s.size=20;
   if(t==NULL) return;
  	BSTptr l,T;l=NULL;
	push(s,l);
	do{
		
		if(t->lc==NULL && t->rc==NULL)
		   {
			 cout<<t->data<<" ";
			   t=pop(s);
	
			 if(t->lc!=NULL)
			 {
			 	push(s,t->lc);
			 	t->lc=NULL;
			 }
		  }
		  
		  else
		  { 
		      T=new BSTnode;
		     	T->data=t->data;
		  	  T->lc=NULL;T->rc=NULL;
		  	  push(s,T);
		    if(t->lc!=NULL)
			 {
			 	push(s,t->lc);
			 	t->lc=NULL;
			 }
		  	
		  	t=t->rc;
		  }
	  }
	while(s.element[s.top] != NULL);
	cout<<t->data;
	
}
int main()
{
	BSTptr  T ;T=NULL;
	creat(T);
	printRLD(T);
	return 0;
}

