#include<iostream>
using namespace std;
struct stack{
	int sice;
	int element[20];
	int top;
}s1,s2;

void push(struct stack &s,int x)
{  
     if(s.top==s.sice-1)
      cout<<"stack is full\n";
      else
      s.element[++s.top]=x;
}

int pop(struct stack &s)
{  
    if(s.top==-1)
    cout<<"stach is empty\n";
    else
    return(s.element[s.top--]);
}

void print(struct stack &s)
{ 
   while(s.top!=-1)
    cout<<pop(s)<<" ";
}

void addbegin(struct stack &s1,struct stack &s2,int x)
{ 
    while(s1.top!=-1)
    {
	  push(s2,pop(s1));
	}
    push(s2,x);
    cout<<"element after adding\n";
}

void addend(struct stack &s1,struct stack &s2,int x)
{ 
	  push(s1,x);
	  while(s1.top!=-1)
	  {
	    push(s2,pop(s1));
	  }
	  cout<<"element after adding\n";
}

void delbeg(struct stack &s1,struct stack &s2)
{
   while(s1.top!=-1)
   {
     push(s2,pop(s1));
	}
    s2.top--;
   cout<<" after deletion of element \n";
}

void delend(struct stack &s1,struct stack &s2)
{ 
	  s1.top--;
	  while(s1.top!=-1)
	  {
	    push(s2,pop(s1));
	  }
	  cout<<" after deletion of element \n";
}

 void addafter(struct stack &s1,struct stack &s2,int p,int x)
 { 
	    while(s1.top!=-1)
	     {
		   if(s1.top==p-1)
	        {
			  push(s2,x);
			   p=-6;
			}
	        else
	        push(s2,pop(s1));
	      } 
	      cout<<"element after adding\n";
 }
 
 void delafter(struct stack &s1,struct stack &s2,int p)
 { 
    while(s1.top!=-1)
     {
	   if(s1.top==p)
         {
		   s1.top--;
		}
        push(s2,pop(s1));
      } 
      cout<<" after deletion of element\n";
 }
 
int main()
{
	s1.sice=20;s2.sice=20;
	s1.top=-1;s2.top=-1;
	int a[20],n,p,x,pos;
	cout<<"enter array size\n";
	cin>>n;
	cout<<"enter array elements\n";
	for(int i=0;i<n;i++)
	 cin>>a[i];
	for(int i=0;i<n;i++)
	  push(s1,a[i]);
	cout<<"press: 1.add-begin \n 2.add-end \n 3.delete-begin \n 4.delete-end \n 5.add-after \n 6.delete-after\n";
	cin>>p;
			switch(p)
			{case 1:cout<<"enter element\n";
			         cin>>x;
			         addbegin(s1,s2,x);
				     print(s2);break;
			 case 2:cout<<"enter element\n";
			        cin>>x;
			        addend(s1,s2,x);
			        print(s2);break;
			 case 3:delbeg(s1,s2);
			         print(s2); break;
			 case 4:delend(s1,s2);
			         print(s2);break;
			 case 5:cout<<"enter position\n";
			        cin>>pos;
			        cout<<"enter element to be added\n";
					cin>>x;
			        addafter(s1,s2,pos,x);
					print(s2);break;
			 case 6:cout<<"enter position\n";
			        cin>>pos;
			        delafter(s1,s2,pos);
					print(s2);
			}
return 0;
}
