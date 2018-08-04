#include <iostream>
#include<cstring>
using namespace std;
struct stack{ 
    int size;
    int ele[50];
    int top;
}stk;

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
	cout<<"stack is full"<<endl;
    else
	s.ele[++s.top]=a;
   }
   
int main()
{
    char exp[50];
    stk.top=-1;
    stk.size=50;int i=0;
    cout<<"enter the expression :"<<endl;
    cin>>exp;
    while(exp[i]!='\0')
	{
            if(exp[i]>=48 && exp[i]<=57)
			{
                push(stk,exp[i]-48);
            }
            else
			{
                int a=pop(stk);
                int b=pop(stk);
                switch(exp[i])
				{
                    case '+': push(stk,a+b);break;
                    case '-': push(stk,a-b);break;
                    case '*': push(stk,a*b);break;
                    case '/': push(stk,a/b);break;
                    case '%': push(stk,a%b);
                }
            }
            i++;

    }
    cout<<"evaluated value is "<<pop(stk);
    return 0;
}
