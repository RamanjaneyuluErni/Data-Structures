#include<iostream>
#include<cstring>
using namespace std;
typedef
struct etnode{
	int tag;
	 union u
	 {
	 	char ch; // tag=1
	 	int d; // tag=0
	 }data;
	struct etnode *lc;
	struct etnode *rc;
}*etptr;

struct stack{
	int sice;
	etptr element[20];
	int top;
};

void push(struct stack &s,etptr &x)
{
    if(s.top==s.sice-1)
      cout<<"stack is full\n";
   else
    s.element[++s.top]=x;
}

etptr pop(struct stack &s)
{
    if(s.top==-1)
    cout<<"stack is empty\n";
    else
     return(s.element[s.top--]);
}

void creat(etptr &t,char exp[],int len)
{
	struct stack s1;s1.top=-1; s1.sice=20;
    for(int i=0;i<len;i++)
	{
        if(exp[i]>=48 && exp[i]<=57)
		{
		    t=new(struct etnode);
		    t->tag=0;
		    t->data.d=exp[i]-48;
		    t->lc=NULL;
			t->rc=NULL;
			push(s1,t);
		}
		else
		{
		    etptr p=pop(s1);
	    	etptr q=pop(s1);
			t=new(struct etnode);
			t->tag=1;
			t->data.ch=exp[i];
			t->lc=p;
			t->rc=q;
		    push(s1,t);
		}
	}

}

void DLRprint(etptr t)
{
    if(t==NULL)return;
    else
      {
        if(t->tag==0)
        cout<<t->data.d;
        if(t->tag==1)
       	   {
            cout<<t->data.ch;
       		DLRprint(t->lc) ;
       		DLRprint(t->rc) ;
		   }
	   }
}
 int eval(int a,int b,char c)
 {
     switch(c)
     {
         case '*':return a*b;break;
         case '-':return a-b;break;
         case '/':return a/b;break;
         case '+':return a+b;
     }
 }
int evaluate(etptr t)
{

    if(t!=NULL)

    {
        if(t->tag==0)
        {

            return(t->data.d);
        }
        else
        {
           return (eval(evaluate(t->lc),evaluate(t->rc),t->data.ch));
        }
    }

}
int main()
{
	etptr t;char exp[20];int l;
	cout<<"enter the postfix expression :"<<endl;
    cin>>exp;
    l=strlen(exp);
    creat(t,exp,l);
	DLRprint(t);
	cout<<"evaluating postfix expression = "<< evaluate(t);
	return 0;
}
