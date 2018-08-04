#include <iostream>
#include<cstring>
using namespace std;
struct stack
{
   int sice;          
   long int ele[20];
   int top;         
};
long int pop(struct stack &s)
{
    if(s.top==-1)cout<<"stack is empty"<<endl;
    else return s.ele[s.top--];
}
void push(struct stack &s,long int a)
{
    if(s.sice-1==s.top)cout<<"stack is full\n";
    else s.ele[++s.top]=a;
}
struct queue
{
	int sice;
	int front;
	int rear;
	char ele[20];
};
char dequeue(struct queue &q)
{       
   if(q.front==-1) cout<<"queue is empty\n";
   else 
    {  
	    char t=q.ele[q.front];
        if(q.front==q.rear)
        {
		   q.front=-1;q.rear=-1;
	    }
        else q.front=(q.front+1)%(q.sice);
	    return t;
	}
}
void enqueue(struct queue &q,char x)
{
	if((q.rear+1)%(q.sice)==q.front) cout<<"queue is full\n";
	else{
           if(q.rear==-1) {q.front=0;q.rear=0;} 
		   else q.rear=(q.rear+1)%q.sice;
		   q.ele[q.rear]=x;
		}
}
int main()
{
  char exp1[20],exp[20],a;//-+*9+28*+4863
  struct stack s1;s1.sice=20;s1.top=-1;
  struct queue q;q.sice=20;q.front=-1;q.rear=-1;
  cout<<"enter infix exp\n";
  cin>>exp1;
  for(int i=0;exp1[i]!=0;i++) enqueue(q,exp1[i]);
  int k=0;
  while(q.front!=-1)
  {
  	 exp[k++]=dequeue(q);
  }
  strrev(exp);cout<<exp<<" jwejhkfh";
  for(int i=0;exp[i]!=0;i++) enqueue(q,exp[i]);
  while(q.front!=-1)
  {
  	a=dequeue(q);cout<<a<<"dlfkj\n";
  	if(a>=48 && a<=57) 
	  {
	  	//cout<<(a-48)*2<<"jknrkg";
	  	push(s1,a-48);
	  	//if(q.front==-1)break;
	  }
  	else
  	{
  		for(int k=0;k<=s1.top;k++) cout<<s1.ele[k]<<" ";cout<<endl;
  		
  		int p=pop(s1);int b=pop(s1);
  		cout<<"p value ="<<p<<endl;
  		cout<<"b value ="<<b<<endl;
  		int m;
  		switch(a)
  		{
  		   case '*':m=p*b;push(s1,m); break;
		   case '+':cout<<"smd]\n"<<p+b;push(s1,(a+b)); break;
		   case '-':cout<<"smd]\n"<<p-b;push(s1,(p-b)); break;
		   case '/':cout<<"smd]\n"<<p/b;push(s1,(p/b)); break;
		}
	}
  }
  cout<<"\n"<<pop(s1);
  return 0;
}    
