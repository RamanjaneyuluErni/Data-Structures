#include <iostream>
#include<cstring>
using namespace std;
struct stack
{
    int size;
    int ele[20];
    int top;
}s1,s2;
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
int main()
{
	s1.top=-1;s1.size=20;s2.top=-1;s2.size=20;
	int n,a[20];
	cout<<"no of elements\n";cin>>n;
	cout<<"enter elements to be sorted\n";
	for(int i=0;i<n;i++)
	    cin>>a[i];
	cout<<"pushing into stack s1\n";
	for(int i=0;i<n;i++)
	    {
	    	push(s1,a[i]);
		}
	while(s1.top!=-1)
	{
		for(int j=0;j<s1.top;j++)
		{
			if(s1.ele[j]>s1.ele[j+1])
			{
				int t;
				t=s1.ele[j];
				s1.ele[j]=s1.ele[j+1] ;
				s1.ele[j+1]= t ;
			}
		}
		push(s2,pop(s1));
		
	}
	cout<<"sorted list\n";	
	while(s2.top!=-1)
	{
		cout<<pop(s2)<<" ";
	}
	return 0;
}
