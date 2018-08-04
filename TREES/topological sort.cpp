#include<iostream>
#include<cstring>
using namespace std;
typedef
struct lnode
		   {
		   	 struct tpnode *p;
	         struct lnode *next;         
		   }*lptr;
typedef
struct tpnode{
                char data;
                int flag;
                lptr ptr;
                struct tpnode *next;
             }*tptr;
 void addend(lptr &T,tptr &t)  
 {
 	if(T==NULL)
 	{
 		T=new lnode;
 		T->p=t;
 		T->next=NULL;return;
    }
    lptr l=T;
    while(l->next!=NULL) l=l->next;
    l->next=new lnode;
    l=l->next;
    l->next=NULL;
    l->p=t;
 }           
 void addptr(tptr &T,tptr &t,char d) 
 {
 	tptr l=T;
 	while(l->next!=NULL)
 	{
 		if(l->data==d)
 		{
 	      t->flag++;addend(l->ptr,t);
 	      return;// we can use (return) to stop execution of further prg
		}
		l=l->next;
	 }	
 }           
void create(tptr &T,char d)
{
    if(T==NULL)	
    {
    	T=new tpnode;
    	T->data=d;T->flag=0;T->next=NULL;
    	T->ptr=NULL;
    	return;
    }
	tptr t=T;
	while(t->next!=NULL)t=t->next;
	t->next=new tpnode;
	t=t->next;
	t->data=d;
	t->flag=0;
	t->next=NULL;
	t->ptr=NULL;
	char ch;
	cout<<"enter courses have to do before(# to stop)\n";
	while(1)
	{   tptr k=T;
		cin>>ch;
		if(ch=='#')break;
	    addptr(k,t,ch);
	}
	
}
int find(tptr &t,char d)
{
	tptr l=t;
	while(l!=NULL)
	{
		if(l->data==d && l->flag==0)
		{
			return 1;
		}
		l=l->next;
	}
	return 0;
}

void displaycourses(tptr &t)
{
	tptr l=t;
	while(l!=NULL)
	{
		if(l->flag==0)
		cout<<l->data<<" ";
		l=l->next;
	}
}
void docourse(tptr &t,char d)
{
	tptr l=t;
	while(l!=NULL)
	{
		if(l->data==d )
		{
			l->flag--;
			lptr k=l->ptr;
			while(k!=NULL)
			{
				k->p->flag--;
				k=k->next;
			}
			return;
		}
		l=l->next;
	}
}
int main()
{
	tptr t=NULL;char d;int courses=0;
	while(1)
	{ 
	  cout<<"enter course name(# to stop)\n";
	  cin>>d;
	  if(d=='#')break;
	  courses++;
	  create(t,d);
     }
     while(courses>0)
     {
     	cout<<"\navailable courses\n";
        displaycourses(t);
        cout<<"\nenter couse to do\n";
        cin>>d;
        if(find(t,d)==1)
        {
        	docourse(t,d);
           	courses--;
		}
		else 
		cout<<"\noops!! u cant do this course dude\n";
    }
    cout<<" successfully completed all courses\n";
	return 0;
}
