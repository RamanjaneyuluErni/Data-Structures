#include <iostream>//(a(b(cd)e(fgh)i(j)))
#include<cstring>
#include<queue>
#include<iomanip>
using namespace std;
int i=1,k=1;
typedef
struct Tnode{
	            struct Tnode *fc;
				char data;
                struct Tnode *ns;
                int tag;
             }*ptr;
             
void create(ptr &t,char exp[])
{
	ptr T=t;
	while(true)
  {
  	  if(exp[i]=='(')
		{
		   i++;
		   T->fc=new Tnode;T->fc->tag=0;
		   T->fc->fc=NULL;T->fc->ns=NULL;
		   create(T->fc,exp);
		}
	    else if(exp[i]==')') 
		  {
		     i++;return;
		  }
		  
		else T->data=exp[i++];
        if(exp[i]!=')' && exp[i]!='(')
		{
		   T->ns=new Tnode;T->ns->tag=0;
		   T->ns->fc=NULL;
		   T->ns->ns=NULL;
		   T=T->ns;
		}
	  if(exp[i]=='\0') break;
   }
}
void printDFT(ptr t)
{
	if(t!=NULL)
	{
		ptr l=t;
		while(l!=NULL)
		{
		   printDFT(l->fc);
		   cout<<l->data<<" ";
		   l=l->ns;
	    }
	}
	else return;
}

void printbft(ptr G)
{
	if(G==NULL)return;
    ptr T=G;
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		printbft(T->fc);
		T=T->ns;
	}
}
void levelprint(ptr &G)
{
	struct queue<ptr>q;ptr T=G,C=NULL;
	q.push(T);q.push(C);
	while(q.size()!=0)
	{
		ptr t=q.front();q.pop();cout<<"\t";
		if(t!=NULL)
		{ 
		  cout<<t->data<<" ";t->tag=k;
		  if(t->fc!=NULL) q.push(t->fc);
		    t=t->ns;
			while(t!=NULL)
			{
				cout<<t->data<<" ";t->tag=k;
				if(t->fc!=NULL) q.push(t->fc);
				t=t->ns;
			}
	
		}
		else 
		{
			cout<<endl;
			if(q.size()!=0) q.push(C);k++;
		}
	}
}
void verticalprint(ptr &G)
{
	struct queue<ptr>q1;ptr T=G,C=NULL;
	q1.push(T);
	while(q1.size()!=0)
	{
		ptr t=q1.front();q1.pop();
        cout<<setw(t->tag)<<t->data<<endl;
		if(t->ns!=NULL) q1.push(t->ns);
		//cout<<"1---";
		t=t->fc;//cout<<"2---";
		while(t!=NULL)
		{
		  cout<<setw(t->tag)<<t->data<<endl;;
		  if(t->ns!=NULL) q1.push(t->ns);
		  t=t->fc;
		}
	}
}
int main()
{
    char exp[20];ptr T;
	cout<<"enter tree elements in set \n";
	cin>>exp;
	T=new Tnode;
	T->fc=NULL;
	T->ns=NULL;T->tag=0;
	create(T,exp);
	cout<<"DFT printing of general tree\n";
	printDFT(T);
	cout<<"\nBFT printing of general tree\n";
	printbft(T);
	cout<<"\nlevelprint\n";
    levelprint(T);
    cout<<"\nvertical print"<<endl;
    verticalprint(T);
 	return 0;
}                        
