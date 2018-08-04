#include<iostream>
using namespace std;
typedef
struct node{
	int data;
	struct node *next;
}*lptr;
void creat(lptr &l)
{int n;lptr t;
cout<<"enter data\n";
cin>>n;
if(n!=-1)
{l=new(struct node);
 l->data=n;
 l->next=NULL;
}	
while (1){
	t=l;
	while(t->next!=NULL)
      {t=t->next;}
      cout<<"enter data value\n";
	cin>>n;
		if(n==-1){break;}
      t->next=new(struct node);
      t=t->next;
	t->data=n;
	t->next=NULL;}	
}
void print(lptr &l)
{lptr t2;t2=l;
   while(t2->next!=NULL)
    {cout<<t2->data<<" ";
      t2=t2->next;
       }
 cout<<t2->data;
}
void merge(lptr &l1,lptr &l2,int p)
{lptr t1,t2,t3;t3=t1;t1=l1;t2=l2;int k=1;
   while(t1->next!=NULL)
     {t1=t1->next;t3=t3->next;}
     while(t2->next!=NULL)
     {
      if(k==p-1){t1->next=t2->next;}
      k++;
      t2=t2->next;
     }
     t2->next=t3->next;
}
int main()
{lptr l1,l2;int p;
 cout<<"creating first LL\n";
 creat(l1);
 cout<<"creating second LL\n";
 creat(l2);
 cout<<"enter position to link\n";cin>>p;
 merge(l1,l2,p);
 cout<<"after splitting\n";
 print(l1);cout<<endl;
print(l2);
return 0;}
