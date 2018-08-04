#include<iostream>
using namespace std;
typedef
struct node
{
	int data;
	struct node *next;
}*lptr;	

void sort(lptr &l)
{
  lptr t1,t2=l;
  while(t2->next!=NULL)
  {   t1=t2;
      while(t1->next!=NULL)
      {  
		   t1=t1->next;
           if(t1->data>t2->data)
              { 
			    int p=t2->data;
		        t2->data=t1->data;
		        t1->data=p;
		       } 
      }
	 t2=t2->next;
	}	
}
void print(lptr &t)
{
   while(t->next!=NULL)
    {
	  cout<<t->data<<" ";t=t->next;
     }
   cout<<t->data;
}
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
int main()
{
   lptr l=NULL;int d;
   while(1)
	{
		cout<<"enter data:";
		cin>>d;
		if(d==-1) break;
		create(l,d);
	}
   sort(l);
   cout<<"elements after sorting\n";
   print(l);
   return 0;
}

