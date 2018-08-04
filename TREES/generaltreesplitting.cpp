#include<iostream>//(a(m(bd(z)l)j(y(o(g)pq))ku(vxw)))
using namespace std;
int i=1;
typedef
struct gnode
{
	struct gnode *fc;
	char data;int f;
	struct gnode *ns;
}*GPTR;
void create(GPTR &G,char str[])
{
	GPTR T=G;
	while(1)
	{
	    if(str[i]=='('){i++;T->fc=new(gnode);
	    T->fc->fc=NULL;T->fc->ns=NULL;T->fc->f=0;
		create(T->fc,str);}
	    else if(str[i]==')'){i++;return;}
	    else T->data=str[i++];
	    if(str[i]!=')'&&str[i]!='(')
	    {
	    	T->ns=new(gnode);
	    T->ns->fc=NULL;T->ns->ns=NULL;T->ns->f=0;T=T->ns;
		}
	}
}
int isprinted(GPTR &G)
{
	if(G==NULL)return 1;GPTR T=G;
	if(T->fc==NULL)return T->f;
	int a=1;T=T->fc;
	while(T!=NULL)
	{
		a*=isprinted(T);T=T->ns;
	}
	G->f=a;.
	
	return a;
}
void splitprint(GPTR &G)
{
	if(G==NULL)return;
	GPTR T=G;int j=0;cout<<T->data<<" ";
	if(T->fc==NULL)
	{
		T->f=1;return;
	}T=T->fc;
	while(T!=NULL&&j<2)
	{
		if(isprinted(T)!=1)
		{
			j++;
		splitprint(T);
		}
		T=T->ns;
	}
}
int main()
{
	GPTR G;
	G=new(gnode);G->fc=NULL;G->ns=NULL;G->f=0;
	char str[40];
	cout<<"enter a string: ";
	cin>>str;
	create(G,str);
	while(isprinted(G)==0)
	{
		cout<<endl;
		splitprint(G);
	}
	
	return 0;
}
