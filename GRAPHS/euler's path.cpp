#include<iostream>
#include<cstring>
using namespace std;
int b[20][20],n;char a[10];
typedef
struct lnode
{
	int data;
	lnode *next;
}*lptr;
int degree(int i)
{
	int c=0;
	for(int j=0;j<n;j++)
	{
		if(b[j][i]!=0)c++;  
	}
	return c;
}
void printmatrix()
{
   cout<<"  ";
   for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
   for(int i=0;i<n;i++)
	{
	   cout<<a[i]<<" ";
	   for(int j=0;j<n;j++) cout<<b[i][j]<<" ";cout<<endl;
    }
}  
int addedge(char c1,char c2,int n)
{
	int v,u;
	for(v=0;v<n;v++) if(a[v]==c1) break;if(v==n) return n;
	for(u=0;u<n;u++) if(a[u]==c2) break;if(u==n) return n;
	b[v][u]=1;b[u][v]=1;
	return -1;
}
void createll(lptr &t,int d)
{
	if(t==NULL)
	{
		t=new lnode;t->data=d;t->next=NULL;return;
	}
	lptr l=t;
	createll(l->next,d);
}
void mergell(lptr &l,lptr &l1,int d)
{
	lptr t=l,temp,temp1=l1;;
	while(t->next->data!=d) t=t->next;
	temp=t->next->next;t->next=l1;
	while(temp1->next!=NULL) temp1=temp1->next;
	temp1->next=temp;
}
void createpath(lptr &l,int v)
{
	int j;lptr t=l;
	while(1)
	{
	   if(degree(v)==0)break;
	   for(j=0;j<n;j++)
 		{
 		  if(b[v][j]!=0) 
		   {
		   	  createll(t,j);
		   	  b[v][j]=0;b[j][v]=0;break;
		  }	
		}
		v=j;
	}
 		
}
int find(lptr &t)
{
	lptr l=t;
	while(l!=NULL)
	{
		if(degree(l->data)!=0) return l->data;
		l=l->next;
	}
	return -1;
}
void print(lptr &l)
{
	lptr t=l;
	while(t!=NULL)
	{
		cout<<t->data<<"  ";t=t->next;
	}
}
int main()
{
	int i,j,k,v;char c1,c2;lptr l=NULL;
	cout<<"no of vertices:";cin>>n;
	cout<<"enter vertices\n";
	for(i=0;i<n;i++) 
	{
		cin>>a[i]; for(j=0;j<n;j++) b[i][j]=0; 
	}
	cout<<"enter vertices to join(# to stop)\n";	
	while(1)
	{
		cin>>c1;if(c1=='#') break;cin>>c2;
		if(addedge(c1,c2,n)==n) cout<<"vertex not found\n";
	}
 printmatrix();
 cout<<"enter initial vertex:";cin>>v;
 createll(l,v);
 createpath(l,v);
 print(l);cout<<endl;
 while(1) 
{
	int f=find(l);
 	if(f==-1) break;
 	lptr l1=NULL;
 	createll(l1,f);
 	createpath(l1,f);
 	cout<<"splicing result:";print(l1);cout<<endl;
 	mergell(l,l1,f);
 	cout<<"result after combinig:";print(l);cout<<endl;
}
cout<<"final euler's path:";
lptr t=l;
 while(t!=NULL)
  {
 	cout<<a[t->data]<<" ";t=t->next;
  }
return 0;
}
/*single euler path splising
a b c d e f g h i j k l
a b
b c
c d
d e
e f
f b
b e
b j
a j
b g
e h
e i
g j
i j
j k
j l
i l
i k
e g
g i
h i
*/
