#include<iostream>
using namespace std;
typedef
struct BSTnode{
	struct BSTnode *lc;
	int data;
	struct BSTnode *rc;
}
*BSTptr;

void addend(BSTptr &T,int d);
void creat(BSTptr &T)
{
	int d;	
			cout<<"enter root element (1 to stop)\n";
			cin>>d;
			if(d!=1)
		{T=new(BSTnode);
		T->lc=NULL;
		T->rc=NULL;
		 T->data=d;
	    addend(T,d);
	    }
}
		
void addend(BSTptr &T,int d)
{ 
    BSTptr t=T,t1=T;int k;
                   cout<<"enter left side (1 to stop) "<<d<<endl;
	               cin>>k;
				if(k!=1){
					 t->lc=new(BSTnode);
				              t=t->lc;
			                   t->data=k;t->lc=NULL;t->rc=NULL;
		                      addend(t,k);
				       }
		                    
		         
		           cout<<"enter right side (1 to stop) "<<d<<endl;
	               cin>>k;
	        	if(k==1){return;
				}
			       t1->rc=new(BSTnode);
			       t1=t1->rc;
			       t1->data=k;t1->lc=NULL;t1->rc=NULL;
		   	       addend(t1,k);
		   	       
		   	 

}

void print (BSTptr &T)
{
	if(T!=NULL)
	{
   	print(T->lc);
		cout<<T->data<<" ";}
			else return;
		
		print(T->rc);
}
bool checkBST(BSTptr &T)
{
	if(T==NULL)return false;
	else if (T->lc->data>T->data && T->lc!=NULL) return false;
        else if (T->rc->data<T->data && T->rc!=NULL) return false;  
        else return(checkBST(T->lc) && checkBST(T->rc));
}
int main()
{
	BSTptr  T ;T=NULL;
	creat(T);
	print(T);
	cout<<checkBST(T);
	return 0;
}

