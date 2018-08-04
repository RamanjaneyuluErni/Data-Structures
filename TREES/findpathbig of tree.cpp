#include<iostream>
using namespace std;
typedef
struct mnode
{
	int tag;
	int data;
	struct mnode *next[3];
}
*mptr;
void create(mptr &l)
{
        l=new(struct mnode);
        mptr t=l;int n,b;char ch;
    	t->tag=0;
        t->next[0]=NULL;
        t->next[1]=NULL;
        t->next[2]=NULL;
    	cout<<"enter an element ";
    	cin>>n;t->data=n;
    	cout<<"enter number of branches(1,2,3)0 to exit ";
    	cin>>b;t->tag=b;
        if(b==0||b>3)return;
        for(int i=0;i<b;i++)
        create(t->next[i]);
}
int find(mptr &l,int el)
{
	mptr t=l;
	while(1)
    {
    	switch(t->tag)
    	{
    		case 0:if(t->data==el)return 1;return 0;
    		case 1:	if(t->data==el)return 1;
		        	t=t->next[0];break;
    		case 2:if(find(t->next[0],el)==1||find(t->next[1],el)==1)return 1;return 0;break;
    		case 3:if(find(t->next[0],el)==1||find(t->next[1],el)==1||find(t->next[2],el)==1)return 1;return 0;break;
    		default:return 0;
		}
	}
	return 0;
}
void printroute(mptr &l,int el)
{
		mptr t=l;
	while(1)
    {
    	switch(t->tag)
    	{
    		case 0:if(t->data==el)cout<<t->data<<"->";return;
    		case 1:cout<<t->data<<"->";if(t->next[0]==NULL)return;
		        	t=t->next[0];break;
    		case 2:if(find(t->next[0],el)==1){cout<<t->data<<"->";printroute(t->next[0],el);return;}
    		       else if(find(t->next[1],el)==1){cout<<t->data<<"->";printroute(t->next[1],el);return;}
    		       else return;
    		case 3:if(find(t->next[0],el)==1){cout<<t->data<<"->";printroute(t->next[0],el);return;}
    		       else if(find(t->next[1],el)==1){cout<<t->data<<"->";printroute(t->next[1],el);return;}
    		       else if(find(t->next[2],el)==1){cout<<t->data<<"->";printroute(t->next[2],el);return;}
    		       else return;
    		default:return;
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
