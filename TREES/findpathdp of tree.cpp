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
int find(mptr &l,int el)
{
	mptr t=l;
	while(1)
	{
		if(t->tag==0){if(t->data==el)return 1;return 0;}
		else if(t->tag==1){if(t->data==el)return 1;t=t->next[0];}
		else
		for(int i=0;i<t->tag;i++)
		if(find(t->next[i],el)==1)
		return 1;
	}
	return 0;
}
void printroute(mptr &l,int el)
{
	mptr t=l;
	while(1)
	{
		if(t->tag==0){if(t->data==el)cout<<t->data<<"->";return;}
		else if(t->tag==1){cout<<t->data<<"->";if(t->next[0]==NULL||t->data==el)return;t=t->next[0];}
		else
		for(int i=0;i<t->tag;i++)
		{
			if(find(t->next[i],el)==1){cout<<t->data<<"->";printroute(t->next[i],el);return;}
		}
	}
	return;
}
int main()
{
	mptr l=NULL;
	create(l);
	int el;
	cout<<"enter element to print route ";
	cin>>el;
	cout<<"begin->";
    printroute(l,el);cout<<"end";
	return 0;
}
