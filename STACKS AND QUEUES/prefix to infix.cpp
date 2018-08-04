#include<iostream>
#include<cstring>
#include<stack>
#include<cstdlib>
using namespace std;
void convert(char exp[],struct stack<string>&stk,int l)
{
	if(l==-1) return;
	else
	{
		string temp;temp=exp[l];
		//if(isdigit(exp[l]))
		if(exp[l]>=65 && exp[l]<=90)
		{
			stk.push(temp);convert(exp,stk,l-1);
		}
		else
		{   
			string temp1;temp1=stk.top();stk.pop();
			string temp2;temp2=stk.top();stk.pop();
			string temp3;temp3=temp1+temp2+temp;
			stk.push(temp3);
			convert(exp,stk,l-1);
		}
	}  
}
int main()
{
	char exp[10];//**+AB-+CDEF
	cout<<"enter exp(prefix):";cin>>exp;
	struct stack<string>stk;
	int len=strlen(exp);
	convert(exp,stk,len-1);
	cout<<stk.top();stk.pop();
}

