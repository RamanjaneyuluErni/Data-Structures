#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef
struct tnode{
	int data;
	tnode *lc;
	tnode *rc;
}*tptr;
void create(tptr &t,int d)
{
	if(t==NULL)
	{
		t=new tnode;
		t->lc=NULL;t->rc=NULL;
		t->data=d;return;
	}
	else if(t->data>d) create(t->lc,d);
	else create(t->rc,d);
}
void print_inorder(tptr &t)
{
	stack<tptr>s;
	if(!t) return;
//	cout<<"xcmbm";
	tptr T=t;
	while(true)
	{
		if(T!=NULL)
		{
			s.push(T); T=T->lc;
		}
		else 
		{
			if(!s.empty())
			{
				T=s.top();s.pop();
				cout<<T->data<<" ";
				T=T->rc;
			}
			else break;
		}
	}
}
void Print(tptr &T)
{
	if(T==NULL) return;
	else{
		Print(T->lc);
		cout<<T->data<<" ";
		Print(T->rc);
	}
}
void Morris_inorder(tptr &T)  //without using recursion and stack
{
	tptr t=T;
	while(t!=NULL)
	{
		if(t->lc==NULL)
		{
			cout<<t->data<<" ";
			t=t->rc;
		}
		else 
		{
			tptr predecessor=t->lc;
			
			while(predecessor->rc && predecessor->rc!=t)
			{
				predecessor=predecessor->rc;
			}
			if(!predecessor->rc)
			{
				predecessor->rc=t;
			    t=t->lc;
			}
			else
			{
				predecessor->rc=NULL;
				cout<<t->data<<" ";
				t=t->rc;
			}
		}
		
	}
}
void Morris_preorder(tptr &T)  //without using recursion and stack
{
	tptr t=T;
	while(t!=NULL)
	{
		if(t->lc==NULL)
		{
			cout<<t->data<<" ";
			t=t->rc;
		}
		else 
		{
			tptr predecessor=t->lc;
			
			while(predecessor->rc && predecessor->rc!=t)
			{
				predecessor=predecessor->rc;
			}
			if(!predecessor->rc)
			{
				predecessor->rc=t;
				cout<<t->data<<" ";
			    t=t->lc;
			}
			else
			{
				predecessor->rc=NULL;
				t=t->rc;
			}
		}
		
	}
}
void preorder(tptr &T)
{
   if(!T) return;
   tptr t=T;
   stack<tptr>s;
   while(true)
   {
   	  if(t)
   	  {
   	  	 cout<<t->data<<" ";
   	     if(t->rc) s.push(t->rc);
		 t=t->lc;	
	  }
	  else
	  {
	  	 if(s.empty()) break;
	  	 t=s.top();s.pop();
	  }
   }
}
int main()
{
	tptr T=NULL;int d;
	while(true)
	{
		cin>>d;
		if(d==-1) break;
		create(T,d);
	}
	//Print(T);
	cout<<endl;
	//print_inorder(T);
	//Morris_inorder(T);
	Morris_preorder(T);
	cout<<endl;
	preorder(T);
	return 0;
}
