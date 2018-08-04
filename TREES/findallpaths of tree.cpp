#include<iostream>
using namespace std;
typedef
struct mnode
{
	int tag;
	int data;
	struct mnode **next;
}
*mptr;
struct stack 
{
	int top;
	int elements[20];
	int size;
};
void create(mptr &l)
{
        l=new(struct mnode);
        mptr t=l;int n,b;char ch;
    	t->tag=0;
    	cout<<"enter an element ";
    	cin>>n;t->data=n;
    	cout<<"enter number of branches(1,2,3)0 to exit ";
    	cin>>b;t->tag=b;
    	t->next=new(mptr[b]);
    	for(int i=0;i<b;i++)
    	t->next[i]=NULL;
        if(b==0||b>3)return;
        for(int i=0;i<b;i++)
        create(t->next[i]);
}
void push(struct stack &stk,int el)
{
	if(stk.size-1==stk.top)
	cout<<"stack is full";
	else
	stk.elements[++stk.top]=el;
}
int pop(struct stack &stk)
{
	if(stk.top==-1)
	{
	cout<<"stack is empty";return -1;
	}
	else
	return(stk.elements[stk.top--]);
}
void stackprint(struct stack &stk,int c)
{
	struct stack temp;
	temp.top=-1;
	temp.size=20;
	while(stk.top>-1)
	push(temp,pop(stk));
	while(temp.top>c-1)
	{
		int el=pop(temp);cout<<el<<"->";push(stk,el);
	}
	while(temp.top>-1)cout<<pop(temp)<<"->";
	cout<<"\n";
}
void stackstore(mptr &l,struct stack &s)
{

		mptr t=l;int c=0;
	while(1)
	{
		c++;
		if(t->tag==0){push(s,t->data);stackprint(s,c);return;}
		else if(t->tag==1){push(s,t->data);if(t->next[0]==NULL)return;t=t->next[0];}
		else
		{
			push(s,t->data);
			for(int i=0;i<t->tag;i++)stackstore(t->next[i],s);break;
		}
	}
}
int main()
{
	mptr l=NULL;
	create(l);
	struct stack s;
	s.top=-1;
	s.size=20;
	stackstore(l,s);
	return 0;
}
