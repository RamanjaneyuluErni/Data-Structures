#include<iostream>
using namespace std;
int d;
typedef
struct node{
	           int data;
	           struct node *next;
             }*lptr;
lptr l=new lnode;            
void create(lptr &l)
{
	if(l==NULL)
	{
		cout<<"enter data(LL):";
		cin>>d;
		if(d==-1)return;
		l=new node;
		l->data=d;
		l->next=NULL;
	}
	lptr l1=l;
  while(1)
  {
  	while(l1->next!=NULL) l1=l1->next;
  	cout<<"enter data(LL):";
  	cin>>d;
  	if(d==-1)return;
  	l1->next=new node;
  	l1=l1->next;
  	l1->data=d;
  	l1->next=NULL;
  }
}

lptr mergelists(lptr l1,lptr l2)
{   
	if(l1==NULL && l2==NULL) return l;
	else if (l1==NULL || l2==NULL)
	{
		if(l1==NULL)
		{
			lptr l3=l;
			while(l2!=NULL)
			{
				l3=new node;
				l3->data=l2->data;
				l3=l3->next;
				l3->next=NULL;
				l2=l2->next;
			}
			return l;
		}
	   else if(l2==NULL)
		{
			lptr l3=l;
			while(l1!=NULL)
			{
				l3=new node;
				l3->data=l1->data;
				l3=l3->next;
				l3->next=NULL;
				l1=l1->next;
			}
			return l;
		}
	}
	else
	{
		lptr l3=l;
		if(l1->data<l2->data)
		{
			l3=new node;
			l3->data=l1->data;
			l3->next=NULL;
			l3=l3->next; 
		    mergelists(l1->next,l2);
		}
		else
		{
			l3=new node;
			l3->data=l2->data;
			l3->next=NULL;
			l3=l3->next; 
		    mergelists(l1,l2->next);
		}
	}
}
int main()
{
	lptr l1=NULL,l2=NULL;
	cout<<"create LL-1(ascending order):\n";
	create(l1);
    cout<<"create LL-2(ascending order):\n";
	create(l2);
    lptr l3=mergelists(l1,l2);
    while(l3->next!=NULL)
    {
    	  cout<<l3->data<<"->";
          l3=l3->next;
    }
    cout<<l3->data;
	return 0;
}
