#include<iostream>
using namespace std;
typedef
struct node{
	          int data;
	          struct node *next ;
           }*lptr;

void creat(lptr &l)
    {
	  lptr t;int n;
	  cout<<"enter data\n";
	  cin>>n;
	  if(n!=-1)
	  {
	    l=new node;
		l->data=n;
		l->next=NULL;
	  }
		t=l;
	while(1){
		      while(t->next!=NULL)
			  {
			    t=t->next;
			  }
			  cout<<"enter data\n";
			  cin>>n;
			  if(n!=-1)
			  {
			   t->next=new node;
			   t=t->next;
			   t->data=n;
			   t->next=NULL;
			  }
			 else {break;}
			}
	}

void intersection(lptr &l1,lptr &l2)
	{
	 lptr t1,t2;t1=l1;
	 int i=0,a[20],f=0;
	   
	  while(1)
	    {
		    t2=l2;
	    	while(1)
			{
	    		if(t1->data==t2->data)
	    		{
				   if(i==0)
				   {
				      a[i]=t1->data;
				      i++;
				   }
	    		 else{
				       int k=0;
				       while(k<=i)
	    		 	{
					  if(a[k]==t1->data)
					   {
						   f=1;  
					       break;
						}  k++;
					   
					}
					    if(f==0)
					  {a[i]=t1->data;i++; }
				    }
				 }
				if(t2->next==NULL)
					{
					   break;
			     	}
				
				t2=t2->next;
			}
			if(t1->next==NULL)
					{
					  break;
				     }
				t1=t1->next;
			
		}
			
cout<<"intersection elements\n";
	for(int k=0;k<i;k++)
	 cout<<a[k]<<" ";
}
	
void unill(lptr &l1,lptr &l2)
{
	 lptr t1,t2;t1=l1;t2=l2;
	 int a[50],i=0,f;	
	 while(1)
	 {
	    f=0;
	   if(i==0)
	 	 { 
		    a[i]=t2->data;
			i++;
	   	 }
	   else
	     {	
			   for(int k=0;k<=i;k++)
		 	   {
				  if(a[k]==t2->data)
		    	    { f=1;
					}
			   }
		    	if(f==0)
		 	  {
			    a[i]=t2->data;
				i++;
			  }
		 }
	 	if(t2->next==NULL)
		 {
		   break;
		 }
		 t2=t2->next;
	 }
	 
	 while(1)
	 { 
		    f=0;
		   for(int k=0;k<=i;k++)
		 	   {
				  if(a[k]==t1->data)
		    	  { f=1;
				     }
				}
		  if(f==0)
		 	  {
			     a[i]=t1->data;
				 i++;
			  }
		   if(t1->next==NULL)
		   {
		      break;
			}
			 t1=t1->next;
	}
	
	cout<<"union elements\n";
		 for(int k=0;k<i;k++)
	    	cout<<a[k]<<" ";
}
		
int main()
{
		lptr l1,l2;
		cout<<"creating first LL\n";
		creat(l1);
		cout<<"creating second LL\n";
		creat(l2);
		intersection(l1,l2);
		unill(l1,l2);
    	return 0;
}

