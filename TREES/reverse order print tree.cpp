#include<iostream>
using namespace std;
typedef
struct BSTnode{
	struct BSTnode *lc;
	int data;
	struct BSTnode *rc;
}
*BSTptr;

struct queue{
	int sice;
	int front;
	int rear;
	BSTptr element[20];
}q;

struct stack{
	int size;
	int ele[20];
	int top;
}s;

void push(struct stack &s,int x)
   {  
       if(s.top==s.size-1)
           cout<<"stack is full\n";
        else
       s.ele[++s.top]=x;
   }
   
int pop(struct stack &s)
   {  
        if(s.top==-1)
          cout<<"stach is empty\n";
        else
        return(s.ele[s.top--]);
   }

BSTptr dequeue(struct queue &q)
  {       
        if(q.front==-1)
              {cout<<"queue is empty\n";}
        else 
         {  
		    BSTptr t;
            t=q.element[q.front];
            if(q.front==q.rear)
                  {
		              q.front=-1;q.rear=-1;
				   }
            else
               {
			         q.front=(q.front+1)%(q.sice);
			    }
            return(t);
	      }
   }
   
void enqueue(struct queue &q,BSTptr x)
    {
	     if((q.rear+1)%(q.sice)==q.front)
                  {
				     cout<<"queue is full\n";
					}
        else{
              if(q.rear==-1)
			       {
				        q.front=0;q.rear=0; 
					}
             else
			      {
                     q.rear=(q.rear+1)%q.sice;
				  }
                q.element[q.rear]=x;
			}
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

void print(BSTptr &T)
{  
   q.sice=20;q.front=-1;q.rear=-1;
   s.top=-1;s.size=20;	
    BSTptr l,t;
   l=new BSTnode;
   l=NULL;//l->lc=NULL;l->rc=NULL;
     enqueue(q,T);
     enqueue(q,l);
   while(q.front!=-1)
    {
	   t=dequeue(q);
	   
       if(t!=NULL)
	  {
      	   push(s,t->data);
	      if(t->lc!=NULL)
	         enqueue(q,t->lc);
	      if(t->rc!=NULL)
	          enqueue(q,t->rc);
       }
        else
	  {
	  	   push(s,0);
	  	   if(t!=NULL)
	  	   {
			 enqueue(q,l);
		   }
	  }
	}
	
	while(s.top!=-1)
	{  
	   int p=pop(s);
		if(p==0)
		{
			cout<<endl;
		}
		else
		{
		   cout<<p<<" ";
	     }
	}
}
int main()
{
    
	BSTptr T ;
	T=NULL;
	creat(T);
	print(T);
	return 0;
}

