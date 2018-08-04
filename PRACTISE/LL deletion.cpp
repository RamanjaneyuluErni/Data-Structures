#include<iostream>
using namespace std;
typedef
struct node{
	        int data;
	        struct node *next ;
}*lptr;
void create(lptr &l,int d)
{
	if(l==NULL)
	{
		l=new node;
		l->data=d;
		l->next=NULL;
	}
	else create(l->next,d);
}
void delet(lptr &l)
{
	int k=0,f=0;lptr l2,l1;
	if(l==NULL) return;
	while(1)
	{
	   int d=l->data-k;
	   l1=l;
	   for(int i=1;i<d-1;i++)
	   {
	   	 if(l1->next==NULL)
	   	 {
	   	 	int f=1;break;
		 }
	     l1=l1->next;
	    }
	    if(f==1)break;
	   l2=l1;
	   if(l1->next!=NULL)l1=l1->next;
	   if(l1=NULL) break;
	   while(l1->next!=NULL)
	   {
	   	 l1->data=l1->next->data;
	   	 l1=l1->next;
	   	 l2=l2->next;
	   }
	   l2->next=NULL;
	   delete(l1);
	   k++;
	}
}
void print(lptr &t)
{
	lptr l=t;
	while(l->next!=NULL)
	{
	  cout<<l->data<<"->";l=l->next;
	}
	cout<<l->data;
}
int main()
{
	lptr t=NULL;int d;
	while(1)
	{
		cout<<"enter data:";
		cin>>d;
		if(d==-1) break;
		create(t,d);
	}
	print(t);
	delet(t);cout<<endl;
    print(t);
    return 0;
}
