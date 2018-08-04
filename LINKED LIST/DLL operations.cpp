#include<iostream>
using namespace std;
typedef
struct dlnode
     {struct dlnode *left;
                int data;
      struct dlnode *right;
     }*dptr;
void addend(dptr &l)
{dptr t,t1;t=l;int d;
   t1=l;
  while(1)
  {cout<<"enter data\n";cin>>d;
    if(d!=-1)
       {t->right=new(struct dlnode);
            t=t->right;
            t->data=d;
            t->right=NULL;
            t->left=t1;t1=t;}
   else
       {break; }
  }}
 void creat(dptr &l)
{int d;
cout<<"enter data\n";
cin>>d;
 if(d!=-1)
 {l=new(struct dlnode);
  l->data=d;
  l->left=NULL;
  l->right=NULL;
 }
  addend(l);
}
void delend(dptr &l)
{dptr t;t=l;
while(t->right!=NULL)
  {t=t->right;}
  t->left->right=NULL;
  t->left=NULL;
  delete(t);
}
void print(dptr &l)
{dptr t;t=l;
while(t->right!=NULL)
{cout<<t->data<<" ";
   t=t->right;}
  cout<<t->data;
}
void addafter(dptr &l,int p,int x)
{dptr t,t2,t1;t=l;int k=0;
  while(1)
  {if(k==p-1){t2=t->right;
         t->right=new(struct dlnode);
        t1=t;t=t->right;t->data=x;t->left=t1;t->right=t2;t2->left=t;
        t1=t->right;break;
         }
  else {k++;t=t->right;}
  }
}
void delafter(dptr &l,int p)
{dptr t;t=l;int k=0;
while(1)
{if(k==p)
{t->left->right=t->right;
  t->right->left=t->left;
  delete(t);break;
}
else
{t=t->right;k++;}
}
}
void delbeg(dptr &l)
{
  dptr t,t1;t=l;t1=t;
  t=t->right;t->left=NULL;l=t;t1->right=NULL;
  delete(t1);
}
int main()
{dptr l;int x,p,k;
creat(l);
cout<<"press: 1.add-after  \n 2.delete-begin \n 3.delete-end \n 4.delete-after\n";
cin>>k;
switch(k)
{case 1:cout<<"enter pos and element\n";cin>>p>>x;
          addafter(l,p,x);
	  print(l);break;
case 2: delbeg(l);
          print(l);break;
case 3:delend(l);
        print(l);break;
case 4:cout<<"enter pos\n";cin>>p;delafter(l,p);
       print(l);break;}
 return 0;
}
