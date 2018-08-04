#include<iostream>
#include<cstring>
using namespace std;
typedef
struct etnode{
	         int flag;
	union u{
		      int d; //flag=1
		      struct tnode
			  {       //flag=0
		        char ch;
				struct etnode *lc;
		       	struct etnode *rc;
		      }ptr;
		    }data;
}*etptr;
struct stack{
	int size;
	etptr element[20];
	int top;
};

void push(struct stack &s,etptr &x)
{
    if(s.top==s.size-1)
      cout<<"stack is full\n";
   else
    s.element[++s.top]=x;
}

etptr pop(struct stack &s)
{
    if(s.top==-1)
    {
	  cout<<"stack is empty\n";
    }
    else
     return(s.element[s.top--]);
}			
void creat(etptr &t,char exp[],int len)
{ stack s;s.top=-1;s.size=20;
    for(int i=0;i<len;i++)
    {
    		if(exp[i]>=48 && exp[i]<=57)
		{
		    t=new etnode;
		    t->flag=1;
		    t->data.d=exp[i]-48;
			push(s,t);
		}
		else
		{
		    etptr p=pop(s);
	        etptr q=pop(s);
			t=new etnode;
			t->flag=0;
			t->data.ptr.ch=exp[i];
			t->data.ptr.lc=p;
			t->data.ptr.rc=q;
		    push(s,t);
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
        if(t->flag==1)
        {

            return(t->data.d);
        }
        else
        {
           return (eval(evaluate(t->data.ptr.lc),evaluate(t->data.ptr.rc),t->data.ptr.ch));
        }
    }

}
void LRDprint(etptr t)
{
    if(t==NULL)
     return;

	 else
      {

        if(t->flag==1)
          {
		  cout<<t->data.d;
          }
        if(t->flag==0)
       	   {

			cout<<t->data.ptr.ch;
       		LRDprint(t->data.ptr.lc) ;
       		LRDprint(t->data.ptr.rc) ;

			}
	   }

      }
		
int main()
	{
	  etptr t;t=NULL;
	  char exp[20];
	  cout<<"enter postfix expression\n";
	  cin>>exp;
	  int l=strlen(exp);
	  creat(t,exp,l); 
     LRDprint(t);
     cout<<"\nevaluating postfix expression = "<< evaluate(t);
	  return 0;
	}
