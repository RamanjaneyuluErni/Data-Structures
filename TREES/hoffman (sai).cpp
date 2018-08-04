#include<iostream>
#include<cstring>
using namespace std;
typedef
struct hnode
{
	struct hnode *lchild;
	char ch;
	int freq;
	struct hnode *rchild;
}
*HPTR;
typedef
struct node
{
	HPTR data;
	node *next;
}*LPTR;
struct stack
{
	int top;
	int size;
	int elements[30];
};
void push(struct stack &stk,int a)
{
	if(stk.size-1==stk.top)
	cout<<"stack is full";
	else
	stk.elements[++stk.top]=a;
}
int pop(struct stack &stk)
{
	if(stk.top==-1)
	{
	cout<<"stack is empty";return -1;
	}
	else
	return(stk.elements[stk.top--]);
}
void addend(LPTR &l,HPTR el)
{
	if(l->data==NULL)
	l->data=el;
	else
	{
		LPTR t=l;
		while(t->next!=NULL)
		t=t->next;
		t->next=new(struct node);
		t=t->next;
		t->data=el;
		t->next=NULL;
	}
}
HPTR delbegin(LPTR &l)
{
	if(l->data==NULL)
	cout<<"no element";
	else
	{
		HPTR d;
		if(l->next==NULL)
		{
		  d=l->data;
		  l->data=NULL;
		  return d;	
		}
		LPTR t;
		t=l;
		l=l->next;
		d=t->data;
		delete(t);
		return (d);
	}
	return NULL;
}
void bubblesort(LPTR &l)
{
	LPTR t1,t2;
	t2=l->next;
	
	HPTR temp;
	while(t2!=NULL)
	{
		t1=l;
		while(t1!=t2)
		{
			if(t1->data->freq > t2->data->freq)
			{
				temp=t1->data;
				t1->data=t2->data;
				t2->data=temp;
			}
			else
			t1=t1->next;
		}
		t2=t2->next;
	}
}
void decode(HPTR h,HPTR T,char *exp,int &i)
{
    while(i<=strlen(exp))
	{
		
		if(h->lchild==NULL){
		cout<<h->ch;h=T;}
		switch(exp[i])
		{
			case '0':i++;
		decode(h->lchild,T,exp,i);break;
			case '1':i++;
		decode(h->rchild,T,exp,i);break;
			case '\0':return;
		}
	}	
	return;
}
void stackprint(struct stack &stk)
{
	struct stack temp;int a;
	temp.size=30;temp.top=-1;
	while(stk.top>-1)
	push(temp,pop(stk));
	while(temp.top>-1)
	{
		a=pop(temp);
		push(stk,a);cout<<a;
	}
	cout<<endl;
}
void printallpaths(HPTR T,struct stack &stk)
{
	if(T->lchild!=NULL)
	{
	if(T->lchild!=NULL)
	{
		push(stk,0);printallpaths(T->lchild,stk);int a=pop(stk);
	}
	if(T->rchild!=NULL)
	{
		push(stk,1);printallpaths(T->rchild,stk);int a=pop(stk);
	}		
	}
	else
	{
		cout<<endl<<T->ch<<" : ";stackprint(stk);
	}
}
int find(HPTR T,char ch)
{
	if(T==NULL)return 0;
	if(T->ch==ch||find(T->lchild,ch)==1||find(T->rchild,ch)==1)return 1;
	return 0;
}
void encode(HPTR H,char exp[])
{
	HPTR T;
	for(int i=0;i<strlen(exp);i++)
	{
	T=H;
	while(T->lchild!=NULL)
	{if(find(T->lchild,exp[i])==1){cout<<"0";T=T->lchild;}
	else if(find(T->rchild,exp[i])==1){cout<<"1";T=T->rchild;}}
	}
}

void print(LPTR &l)
{
	LPTR t=l;
	while(t->next!=NULL)
	{
		 	cout<<t->data->ch<<"  "<<t->data->freq;
		 	t=t->next;
		 
	}
	cout<<t->data->ch<<"  "<<t->data->freq;
	
}

int main()
{
	int freq;
	char c;
	LPTR l;
	l=new(node);l->data=NULL;l->next=NULL;
	cout<<"\nenter data\n";
	do
	{
		cout<<"enter char:";
		cin>>c;
		cout<<"enter freq:";
		cin>>freq;
		HPTR h=new(hnode);
		h->ch=c;
		h->freq=freq;
		h->lchild=NULL;
		h->rchild=NULL;
		addend(l,h);
		cout<<"\nenter more?(y/n)";
		cin>>c;
	}while(c=='y');
	bubblesort(l);
	print(l);
	while(l->next!=NULL)
	{
		HPTR T;
		T=new(hnode);
		T->freq=l->data->freq+l->next->data->freq;
		T->ch='*';
		T->lchild=l->data;
		T->rchild=l->next->data;
		delbegin(l);
		l->data=T;
		bubblesort(l);
	}
	HPTR h;
	h=l->data;int k=0;
	freq=0;l->data=NULL;
	struct stack stk;
	stk.top=-1;stk.size=30;
	printallpaths(h,stk);
	char dec[50],enc[50];
	cout<<"\nenter code to encode: ";
	cin>>enc;
	cout<<endl;HPTR p=h;
    encode(h,enc);
	cout<<"\nenter code to decode: ";
	cin>>dec;
	cout<<endl;
    p=h;
	decode(h,p,dec,freq);
}
