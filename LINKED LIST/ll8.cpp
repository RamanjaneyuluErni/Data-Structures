#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node *next;
}
*lptr;
void create(lptr &l,int d)
{
	l=new(node);
	l->data=d;
    l->next=NULL;
}
void addbegin(lptr &l,int d)
{
	if(l==NULL)
	{
		l=new(node);
		l->data=d;
		l->next=NULL;
	}
	else
	{
    lptr t=new(node);
    t->data=l->data;
    t->next=l->next;
    l->data=d;
    l->next=t;}
}
void addend(lptr &l,int d)
{	lptr t;
	
		if(l==NULL)
	{
		l=new(node);
		l->data=d;
		l->next=NULL;
	}
	else
	{
	t=l;
	while(1)
	{
		if(l->next==NULL)
		break;
		else
		l=l->next;
	}  
	l->next=new(node);
	l->next->data=d;
	l->next->next=NULL;
	l=t;}
}
int digits(int num)
{
	if(num==0)
	return 1;
	int i=0;
	while(num)
	{
		i++;
		num=num/10;
	}
	return i;
}
int maxdigits(int *a,int siz)
{
	int m=digits(a[0]);
	for(int i=1;i<siz;i++)
	{
		int n=digits(a[i]);
		if(m<n)
		m=n;
	}
	return m;
}
int getnth(int num,int i)
{
	int c=0,n;
	while(c!=i)
	{
		n=num%10;
		num=num/10;
		c++;
	}
	return n;
}
int popup(lptr &l)
{
	int x;
	x=l->data;
	if(l->next==NULL)
	{
		l=NULL;
	}
	else
	l=l->next;
	return x;
}
int main()
{
	lptr *p;
	p=new lptr[10];
	for(int i=0;i<10;i++)
	{
		create(p[i],0);
	}
	int o;
	cout<<"\nenter num of elements ";
	cin>>o;
	int nums[o];
	for(int i=0;i<o;i++)
	{
		cout<<"\nenter number ";
		cin>>nums[i];
	}
	cout<<"\nbefore sorting array is ";
	for(int i=0;i<o;i++)
	cout<<nums[i]<<" ";
	int n=maxdigits(nums,o);
	for(int i=0;i<n;i++)
	{
		int x=0;
		for(int j=o-1;j>=0;j--)
		{
			int k=getnth(nums[j],i+1);
			addbegin(p[k],nums[j]);
		}
		for(int j=0;j<10;j++)
		{
			while(p[j]->next!=NULL)
			{
				nums[x]=popup(p[j]);
				x++;
			}
		}
	}
	cout<<"\nafter soeting array is ";
	for(int i=0;i<o;i++)
	{
		cout<<nums[i]<<" ";
	}
	return 0;
}


