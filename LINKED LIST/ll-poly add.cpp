#include<iostream>
using namespace std;
typedef
struct node
{
	int co;
	int po;
	struct node *next;
}
*lptr;
void create(lptr &l,int c,int p)
{
	l=new(node);
	l->co=c;
	l->po=p;
    l->next=NULL;
}
void addbegin(lptr &l,int c,int p)
{
	lptr t;
	t=new(node);
	t->co=c;
	t->po=p;
	t->next=l;
	l=t;
}
void deletebegin(lptr &l)
{
	l=l->next;
}
void addend(lptr l,int c,int p)
{
	lptr t=l;
	while(1)
	{
		if(l->next==NULL)
		break;
		else
		l=l->next;
	}
	l->next=new(node);
	l->next->co=c;
	l->next->po=p;
	l->next->next=NULL;
	l=t;
}
void print(lptr l)
{
	int z=1;
    cout<<"\n";
    while(1)
    {
    	if(z==1)
    	cout<<l->co;
    	else 
    	{
    		if(l->co >0)
    		cout<<"+"<<l->co;
    		else if(l->co <0)
    		cout<<l->co;
		}
        
        if(l->po!=0 &&l->co!=0)
        {
        	cout<<"x^";
        cout<<l->po;	
		}
        
        if(l->next==NULL)
            break;
        else
            l=l->next;
        z++;    
    }
}
void sort(lptr &l)
{
	lptr t1,t2;
	int temp1,temp2;
	t2=l->next;
	while(t2!=NULL)
	{
		t1=l;
		while(t1!=t2)
		{
			if(t1->po < t2->po)
			{
				temp1=t1->co;
				temp2=t1->po;
				t1->co=t2->co;
				t1->po=t2->po;
				t2->co=temp1;
				t2->po=temp2;
			}
			else
			t1=t1->next;
		}
		t2=t2->next;
	}
}
void addp(lptr l1,lptr l2)
{
	sort(l1);
	sort(l2);
	lptr t1,t2,l;
	t1=l1;
	print(t1);
	t2=l2;
	create(l,0,0);
	while(t1!=NULL&&t2!=NULL)
	{
		if(t1->po > t2->po)
		{
			addend(l,t1->co,t1->po);
			t1=t1->next;
		}
		else if(t2->po > t1->po)
		{
			addend(l,t2->co,t2->po);
			t2=t2->next;
		}
		else if(t1->po==t2->po)
		{
			addend(l,t1->co+t2->co,t1->po);
			t1=t1->next;
			t2=t2->next;
		}
	}
	while(t1!=NULL)
	{
		addend(l,t1->co,t1->po);
		t1=t1->next;
	}
	while(t2!=NULL)
	{
		addend(l,t2->co,t2->po);
		t2=t2->next;
	}
	cout<<"\naddition is \n";
	deletebegin(l);
	print(l);
}

int main()
{
	int x,i,j,k;
	lptr l1,l2;
	create(l1,0,0);
	create(l2,0,0);
	cout<<"enter the no. of terms in polynomial 1 ";
	cin>>x;
	for(i=1;i<=x;i++)
	{
		cout<<"\nenter coefficient of x ";
		cin>>j;
		cout<<"\nenter power of x ";
		cin>>k;
		addend(l1,j,k);
	}
	deletebegin(l1);
		cout<<"enter the no. of terms in polynomial 2";
	cin>>x;
	for(i=1;i<=x;i++)
	{
		cout<<"\nenter coefficient of x ";
		cin>>j;
		cout<<"\nenter power of x ";
		cin>>k;
		addend(l2,j,k);
	}
	deletebegin(l2);
	addp(l1,l2);
}
