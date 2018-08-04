
#include <iostream>
#include<cstring>
using namespace std;
typedef
struct Tnode{
            
             struct Tnode *lc; 
			 int data;
             struct Tnode *rc;
           }*ptr;

struct queue{
				int size;
				int front;
				int rear;
				ptr ele[20];
           }q;
ptr dequeue(struct queue &q)
  {       
        if(q.front==-1)
              {cout<<"queue is empty\n";}
        else 
         {  
		    ptr t;
            t=q.ele[q.front];
            if(q.front==q.rear)
                  {
		              q.front=-1;q.rear=-1;
				   }
            else
               {
			         q.front=(q.front+1)%(q.size);
			    }
            return(t);
	      }
   }
   
void enqueue(struct queue &q,ptr x)
    {
	     if((q.rear+1)%(q.size)==q.front)
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
                     q.rear=(q.rear+1)%q.size;
				  }
                q.ele[q.rear]=x;
			}
    }
    

ptr create(struct queue &q)
{
	ptr t1,t2,t;
	while(q.front!=-1)
	{
		t1=dequeue(q);
		t2=dequeue(q);
		if(t1->data>t2->data)
		{
			t=new Tnode;
			t->data=t1->data;
			t->lc=t2;
			t->rc=t1;
			if(q.front!=-1)
			 enqueue(q,t);
		}
		else if(t1->data<t2->data)
		{
			t=new Tnode;
			t->data=t2->data;
			t->lc=t1;
			t->rc=t2;
			if(q.front!=-1)
			enqueue(q,t);
		}
	}
	return t;
	
}

void print(ptr &T,struct queue &q)
{  	
    ptr l,t;
   l=new Tnode;
   l=NULL;
     enqueue(q,T);
     enqueue(q,l);
   while(1)
    {
	   t=dequeue(q);
	   
       if(t!=NULL)
	  {     
      	   cout<<t->data<<"    ";
	      if(t->lc!=NULL)
	         enqueue(q,t->lc);
	      if(t->rc!=NULL)
	          enqueue(q,t->rc);
       }
        else
	  {
	  	   cout<<endl<<endl;
	  	  if(q.front==-1)
			{   break;}  //othrwise loop will goes to infinite
	  	   enqueue(q,l);
	  
	}
}}

int main()
{
	q.size=20;q.front=-1;q.rear=-1;
	int d;
	ptr t;t=NULL;
	while(1)
	{
	   cout<<"enter data(-1 to stop)\n";
	   cin>>d;
	   if(d!=-1)
	   {
	   	 t=new Tnode;
	   	 t->data=d;
	   	 t->lc=NULL;
		 t->rc=NULL;
	   	 enqueue(q,t);
	   }
	   else break;
    }
 ptr l=create(q);
 cout<<"printing of tournament tree\n";
 print(l,q);
	return 0;
}
