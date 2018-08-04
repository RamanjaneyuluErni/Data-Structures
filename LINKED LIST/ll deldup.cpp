#include<iostream>
using namespace std;
typedef
struct node{
	int data;
	struct node *next ;
}*lptr;
            void creat(lptr &l)
              {lptr t;int n;
				cout<<"enter data\n";
				cin>>n;
				if(n!=-1)
				{l=new(struct node);
				l->data=n;
				l->next=NULL;
				}
				t=l;
				while(1){
					while(t->next!=NULL){
						t=t->next;
					}
					cout<<"enter data\n";
					cin>>n;
					if(n!=-1)
				    {t->next=new(struct node);
					t=t->next;
					t->data=n;t->next=NULL;}
					else {break;}
				}
				}
	void deldup(lptr &l)
	{
				lptr t1,t2,t3;t1=l;t2=l;t3=l;int f;
			while(t1->next!=NULL)
			{
				while(t3->next!=NULL)
				    {int f=0;
			      	t2=t2->next;
				    if(t2->data==t1->data)
				   { if(t3->next->next!=NULL)
				   {t3->next=t3->next->next;
				      t3=t3->next;
				    delete(t2);t2=t3;}
				    else if(t3->next->next==NULL)
				    {delete(t2);t3->next=NULL;
					   f=1;break;
				    }}
				   else
				   {t3=t3->next;}
				   }
		
					
		  t1=t1->next;t3=t1;t2=t1;
						
			}
			
}
			void print(lptr &l)	
			{lptr t1;t1=l;
			 while(t1->next!=NULL)
			 {cout<<t1->data<<" ";t1=t1->next;
			 }
			  cout<<t1->data;	
			}
int main()
{lptr l;
creat(l);
cout<<"after deleting duplecate elments\n";
deldup(l);
print(l);
	return 0;
}

