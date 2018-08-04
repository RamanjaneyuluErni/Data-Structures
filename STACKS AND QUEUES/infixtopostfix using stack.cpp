#include <iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int getweight(char x){
    switch(x)
	{
    case '*':return 2;break;
    case '/':return 2;break;
    case '-':return 1;break;
    case '+':return 1;break;
    }
}
struct stack{
    int sice;
    char symbols[100];
    int top;
};
char pop(struct stack &s){
    if(s.top == -1){
        cout<<"stack is empty"<<endl;
    }
    else{return s.symbols[s.top--];}
}
void push(struct stack &s,char ch){
    if(s.sice-1==s.top){cout<<"stack is full"<<endl;}
    else{s.top++;s.symbols[s.top]=ch;}
}
int main()
{
    struct stack stk;
    stk.top=-1;
    stk.sice=20;
    char exp[50]={},t;int upper,lower;
    cout<<"enter the infix expression :"<<endl;
    cin.getline(exp,50);
    for(int i=0;exp[i]!='\0';i++)
	{
        if(exp[i]>=48 &&exp[i]<=57) cout<<exp[i]<<" ";
        else
		{
			if(stk.top==-1){push(stk,exp[i]);}
			else
			{
				do 
				{
				   t=pop(stk);lower=getweight(t);upper=getweight(exp[i]);
				   if(lower>=upper){cout<<t<<" ";}
				   else if(lower<upper){push(stk,t);push(stk,exp[i]);break;}
				}while(lower>=upper && stk.top!=-1);
				if(stk.top==-1)push(stk,exp[i]);
			}
		}
    }
    while(stk.top!=-1) cout<<pop(stk)<<" ";
	return 0;
}
