#include<iostream>
using namespace std;
struct queue{
	int sice;
	int front;
	int rear;
	int element[20];
};
int dequeue(struct queue &q)
{if(q.front==-1)
   {cout<<"queue is empty\n";}
 else 
   {  int t;
     t=q.element[q.front];
     if(q.front==q.rear)
      {q.front=-1;q.rear=-1;}
      else
      {q.front=(q.front+1)%(q.sice);}
     return(t); }
}
void enqueue(struct queue &q,int x)
{if((q.rear+1)%(q.sice)==q.front)
   {cout<<"queue is full\n";}
 else{
      if(q.rear==-1){q.front=0;q.rear=0; }
      else{
      q.rear=(q.rear+1)%q.sice;}
      q.element[q.rear]=x;}
 }
 void addbeg(struct queue &q1,struct queue &q2,int n)
 { enqueue(q2,n);int k;
   while(q1.front!=-1)
    { k=dequeue(q1);
     enqueue(q2,k);
    }
 } 
 void addend(struct queue &q1,int n)
 {  enqueue(q1,n);
 }
 void delbeg(struct queue &q1,struct queue &q2)
 {  int p=dequeue(q1);enqueue(q2,p);
 }
 void delend(struct queue &q1)
 {q1.rear=(q1.rear-1)%(q1.sice);
 }
 void addafter(struct queue &q1,struct queue &q2,int p,int x)
 {int j;
  while(q1.front!=-1)
    {  if((q1.front)%(q1.sice)==p)
       {enqueue(q2,x); }
       j=dequeue(q1);
	   enqueue(q2,j); }
 }
 
 void delafter(struct queue &q1,struct queue &q2,int p)
 {int j;
    while(q1.front!=-1)
   {if((q1.front)%(q1.sice)==p)
     {q1.front=(q1.front+1)%(q1.sice);}
     enqueue(q2,dequeue(q1));}
   }
 void print(struct queue &q)
 { while(q.front!=-1)
   {cout<<dequeue(q)<<" ";}
 }
int main()
{ struct queue s1,s2;
 s1.sice=20;s2.sice=20;s1.front=-1;s2.front=-1;s1.rear=-1;s2.rear=-1;
int a[20],n,p,x,pos;
cout<<"enter array size\n";cin>>n;
cout<<"enter array elements\n";
for(int i=0;i<n;i++)
{cin>>a[i];}
for(int i=0;i<n;i++)
  {enqueue(s1,a[i]);}
cout<<"press: 1.add-begin \n 2.add-end \n 3.delete-begin \n 4.delete-end \n 5.add-after \n 6.delete-after\n";
cin>>p;
switch(p)
{case 1:cout<<"enter element\n";cin>>x;
          addbeg(s1,s2,x);
	  print(s2);break;
case 2:cout<<"enter element\n";cin>>x;
        addend(s1,x);
          print(s1);break;
 case 3:delbeg(s1,s2);
        print(s1);break;
 case 4:delend(s1);
       print(s1);break;
case 5:cout<<"enter position\n";cin>>pos;
        cout<<"enter element to be added\n";cin>>x;
         addafter(s1,s2,pos,x);print(s2);break;
 case 6:cout<<"enter position\n";cin>>pos;
         delafter(s1,s2,pos);print(s2);}

	return 0;
}
