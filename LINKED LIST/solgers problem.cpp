#include<iostream>
#include<cstdlib>
using namespace std;
typedef
struct node{
      	     int data;
	         struct node *next;
           }*lptr;
          
void creat(lptr &l)
{
		int n;lptr t;
		cout<<"enter solger no\n";
		cin>>n;
		if(n!=-1)
		{
		     l=new node;
			 l->data=n;
			 l->next=NULL;
         }	
         
    while (1){
             	t=l;
				while(t->next!=NULL)
			      {
				     t=t->next;
				  }
			      cout<<"enter solger no\n";
				  cin>>n;
				  if(n==-1)
				  {
				    break;
				  }
			      t->next=new node;
			      t=t->next;
				  t->data=n;
				  t->next=NULL;
			}
			t->next=l;	
             
}
void delesol(lptr &temp)
{  
   int r;
   while(temp->next!=temp)
      {
	    r=rand()%10+1;
        cout<<"\nrandom no is "<<r;
         for(int i=1;i<r;i++)
         {
         	temp=temp->next;
		 }
		 
		 temp->next=temp->next->next;
   	  }
   	  cout<<"\nleft solger is "<<temp->data;
}
int main()
{
  lptr l,temp;
  creat(l);
  temp=l;
  delesol(temp);
  return 0;
}
