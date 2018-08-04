#include<iostream>
#include<queue>
using namespace std;
int p[10];
typedef struct hnode
{
	hnode *lc; 
	int freq;
	char ch;
	hnode *rc;
}*hptr;
typedef struct lnode
{
	hptr ptr;
	lnode *next;
}*lptr;
void creatll(lptr &L,hptr H)
{
	if(L==NULL)
	{
		L=new lnode;L->ptr=H;L->next=NULL;return;
	}
	creatll(L->next,H);
}
void bublesort(lptr &l)
{
	lptr l1=l;
	while(l1!=NULL)
	{
		lptr l2=l1->next;
		while(l2!=NULL)
		{
			if(l1->ptr->freq>l2->ptr->freq)
			swap(l1->ptr,l2->ptr);
			l2=l2->next; 
		}
		l1=l1->next;
	}
}
void print(lptr &l)
{
	lptr L=l;
	while(L!=NULL)
	{
		cout<<L->ptr->freq<<"  "<<L->ptr->ch<<endl;
		L=L->next;
	}
}
void delbeg(lptr &l,hptr &H)
{
	lptr L=l->next;delete(l);
    l=L;l->ptr=H;
}
void levelprint(hptr &H)
{
	queue<hptr>q;hptr C=NULL;
	q.push(H);q.push(C);
	while(q.size()!=0)
	{
		hptr t=q.front();q.pop();
		if(t!=NULL)
		{ 
		  cout<<t->ch<<"  "<<t->freq;
		  if(t->lc!=NULL) q.push(t->lc);
		  if(t->rc!=NULL) q.push(t->rc);
		}
		else 
		{
			cout<<endl;if(q.size()!=0)q.push(C);
		}
	}
}
void encode(hptr &H,int n)
{
  if(H==NULL)return;
  else if(H->lc==NULL && H->rc==NULL)
  {
	 cout<<H->ch<<":";
	 for(int k=0;k<=n;k++)cout<<p[n]<<" ";cout<<endl;return;
  }
  else
  {
  	  n++;
      p[n]=0;encode(H->lc,n);
      p[n]=1;encode(H->rc,n);
  }

}
int main()
{
	hptr H=NULL;lptr l=NULL;int f,i=-1;char c;
	while(1)
	{
		cout<<"enter freq:(-1 to stop)";cin>>f;
		if(f==-1)break;
		cout<<"enter char:";cin>>c;
		H=new hnode;H->freq=f;H->ch=c;
		H->lc=NULL;H->rc=NULL;
		creatll(l,H);
	}
	cout<<"sorted list\n";
	bublesort(l);
	print(l);cout<<endl;
	while(l->next!=NULL)
	{
		H=new hnode;H->ch='*';
		H->freq=l->ptr->freq+l->next->ptr->freq;
		H->lc=l->ptr;H->rc=l->next->ptr;
		delbeg(l,H);
		bublesort(l);
		print(l);cout<<endl;
	}
	hptr h=H;
	levelprint(h);
	encode(h,i);
//	cout<<"enter code\n";
//	int a[20],int n;
//	cout<<"enter code to decode\n";
//	cout<<"enter no of elements:";cin>>n;
//	for(int i=0;i<n;i++) cin>>a[i];
//	decode(H,a);
	return 0;
}
/*10
y
12
c
21
d
8
f
4
c
3
a
*/
