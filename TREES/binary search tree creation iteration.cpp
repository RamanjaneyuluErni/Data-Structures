#include<iostream>
using namespace std;
typedef
struct BSTnode{
	struct BSTnode *lc;
	int data;
	struct BSTnode *rc;
}
*BSTptr;

void insert(BSTptr &T,int d )
{
	while(T!=NULL)
	{
	    if(T->data>d)
	        {
	        	if(T->lc!=NULL)
	          	   T=T->lc;
	          	else break;
	        }
	    else if(T->data<d)
	        {
	        	if(T->rc!=NULL)
	         	    T=T->rc;
				 else break;	
	        }

    }
    if(T->data>d)
		{
			T->lc=new(BSTnode);
			T=T->lc;
		}
    else
		{
			T->rc=new(BSTnode);
			T=T->rc;
		}
	T->data=d;
	T->lc=NULL;
	T->rc=NULL;
}

void creat(BSTptr &T)
{
	int d;BSTptr t;
	cout<<"enter root element:(-1 to stop)\n";
	cin>>d;
	if(d!=-1)
	{
	   T=new(struct BSTnode);
	   T->data=d;
	   T->lc=NULL;
	   T->rc=NULL;
    }
    while(1)
    {  t=T;
    		cout<<"enter element to be inserted :(-1 to stop)\n";
			cin>>d;
    		if(d!=-1)
    		{
			   insert(t,d);
			}
			else 
		    {
			    break;
		    }
	}
}
bool checkBST(BSTptr &T)
{
	if(T==NULL)return false;
	else if (T->lc->data>T->data && T->lc!=NULL) return false;
        else if (T->rc->data<T->data && T->rc!=NULL) return false;  
        else return(checkBST(T->lc) && checkBST(T->rc));
}
void print (BSTptr &T)
{
	if(T!=NULL)
	{
      	print(T->lc);
		cout<<T->data<<" ";
	}
    else return;
    print(T->rc);
}
int main()
{ 
    int p,s;BSTptr T=NULL;
	creat(T);
	print(T);cout<<checkBST(T);
	return 0;
}

