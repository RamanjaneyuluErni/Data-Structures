#include<iostream>
using namespace std;
struct queue{
	int front;
	int rear;
	int size;
	int element[10];
}q;

struct stack{
	int top;
	int size;
	int element[10];
	
}s,s1;

void push(struct stack &s,int x)
{
	if(s.top==s.size-1)
	cout<<"stack is full\n";
	else
	s.element[++s.top]=x;
}
	
int pop(struct stack &s)
{  
    if(s.top==-1)
     cout<<" stack is empty\n";
    else
    return(s.element[s.top--]);
}
	
void enqueue(struct queue &q,int x)
{
	if((q.rear+1)%q.size==(q.front))
	    {
	      cout<<"queue is full\n";
		  }
	else
	{  
	  if(q.front==-1) q.front=0;
	  q.rear=(q.rear+1)%q.size;
	  q.element[q.rear]=x;
    } 
}

int dequeue(struct queue &q)
{
		if(q.rear==-1)
		{cout<<"queue is empty\n";}
		else
		{
		   int t=q.element[q.front];
		   if(q.rear==q.front)
		   {
		     	q.front=-1;q.rear=-1;
		   }
		   else
		   {
		     q.front=(q.front+1)%(q.size);
		   }
			
		  return t;	
		}
}
int main()
{
	int d,f=0;
    q.front=-1;q.rear=-1;q.size=10;
	s.top=-1;s.size=10;
	s1.top=-1;s1.size=10;
	cout<<"enter numbers into stack(-1 to break)\n";
	while(1)
	{
		cout<<"enter data:";
		cin>>d;
		if(d==-1)break;
		push(s,d);
	}
	int k=s.top;
	while(s.top>k/2)
	{
		int p=pop(s);
		enqueue(q,p);
	}

	while(s.top!=-1)
	{
		push(s1,pop(s));
	}
	while(s1.top!=-1 && q.front!=-1)
	{
		if(dequeue(q)!=pop(s1))
		{
			f=1;
			break;
		}
	}
	if(f==0)
	cout<<"polindrome\n";
	else
	cout<<"not a polindrome\n";
	return 0;
}
