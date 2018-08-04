#include <iostream>
#include<cstring>
using namespace std;
struct stack{
             int size;
             char ele[20];
             int top;
}s;

int pop(struct stack &s)
  {
    if(s.top==-1)
        cout<<"stack is empty"<<endl;
    else
	   return s.ele[s.top--];
  }
  
void push(struct stack &s,int a)
{
    if(s.size-1==s.top)
	   cout<<"stack is full\n";
    else
	   s.ele[++s.top]=a;
}

struct queue{
			int sice;
			int front;
			int rear;
			char ele[20];
           }q;

char dequeue(struct queue &q)
  {       
        if(q.front==-1)
              {cout<<"queue is empty\n";}
        else 
         {  
		    char t;
            t=q.ele[q.front];
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
   
void enqueue(struct queue &q,char x)
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
                q.ele[q.rear]=x;
			}
    }
    
int check(char x)
{
    switch(x)
	{
	    case '*':return 2;break;
	    case '/':return 2;break;
	    case '-':return 1;break;
	    case '+':return 1;
    }
}

int main()
{
	s.size=20;s.top=-1;
	q.sice=20;q.front=-1;q.rear=-1;
	char exp[20];int i=0;
	cout<<"enter infix exp\n";
	cin>>exp;
	while(exp[i]!='\0')
	{
		if(exp[i]>=48 && exp[i]<=57)
		{
			enqueue(q,exp[i]);
		}
		else                               //converting into postfix and storing in queue
		{
			if(s.top==-1 || check(exp[i])>check(s.ele[s.top]))
			{
				push(s,exp[i]);
			}
			else if(check(exp[i])<=check(s.ele[s.top]))
			{
			    char p=pop(s);
				enqueue(q,p);
				push(s,exp[i]);
			}
		}
		i++;
	}
	while(1)
	{
		if(s.top==-1)
		{
			break;
		}
		else
		enqueue(q,pop(s));
	}
   while(q.front!=-1)
   {
   	  char p=dequeue(q);
   	  if(p>=48 && p<=57)
	   	  {
	   	  	  push(s,p-48);
		  }
	else
		 {
		 	char a=pop(s);
		 	char b=pop(s);
		 	switch(p)
		 	{
		 		case '*':push(s,(a*b));break;
		 	    case '+':push(s,(a+b));break;
		 		case '-':push(s,(b-a));break;
		 		case '%':push(s,(b%a));break;
		 		case '/':push(s,(b/a));
			 }
		 }
   }
   
   cout<<"evaluated value is "<<pop(s);
	return 0;
}
