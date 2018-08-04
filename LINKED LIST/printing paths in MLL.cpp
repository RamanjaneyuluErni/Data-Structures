#include<iostream>
using namespace std;
typedef
struct mnode{
				int tag;
				int data;
				struct mnode **next;
            }*lptr;
            
void create(lptr &t)
{
        t=new mnode;
		lptr l=t; int d,n;
		cout<<"enter data:";cin>>d;
		l->tag=0;
	    l->data=d;
	    cout<<"enter no of next pointers(0 to stop):";
		cin>>n;
		l->tag=n;
		l->next=new lptr[n];
		for(int i=0;i<n;i++) 
		   l->next[i]=NULL;
		if(n==0 || n>3) return;
        for(int i=0;i<n;i++)
	    	create(l->next[i]);
}


void printarray(int a[],int len)

{
		for(int k=0;k<len;k++)
	  {
	  	
	    cout<<a[k];
		if(k!=len-1)cout<<"->";
	  }
}
void printpaths(lptr &l,int a[],int i)
{

	a[i]=l->data;i++;
    for(int k=0;k<l->tag;k++)
	{
		printpaths(l->next[k],a,i);
	}
	if(l->tag==0)
	 {
	   printarray(a,i);
	   cout<<endl;
	   return;
	 }
	
}
int findpath(lptr &l,int a[],int i,int d,int &x)
{
	a[i]=l->data;i++;
	if(l->data==d)
	 {
	 	x=1;
	 	cout<<"found:";
	    printarray(a,i);

	 }
    for(int k=0;k<l->tag;k++)
	{
		findpath(l->next[k],a,i,d,x);
	}

}
int findnode(lptr &l,int d)
{
	if(l==NULL) return 0;
	switch(l->tag)
	{
		case 0:if(l->data==d) return 1;return 0;
		case 1:if(l->data==d) return 1;
		         if(findnode(l->next[0],d)==1) return 1;return 0;
	    case 2:if(l->data==d) return 1;
	             if(findnode(l->next[0],d)==1 ||findnode(l->next[1],d)==1) return 1;return 0;
	    case 3:if(l->data==d) return 1;
	             if(findnode(l->next[0],d)==1 ||findnode(l->next[1],d)==1 ||findnode(l->next[2],d)==1) return 1;return 0;
	}
}
int main()
{
	lptr l;int i=0,a[20],d,k=0;
	l=NULL;
	create(l);
	cout<<"printing pahts of MLL\n";
	printpaths(l,a,i);
	cout<<"enter path to find:";
	cin>>d;
	findpath(l,a,i,d,k);
	if(k==0)
	cout<<"did't found\n";
	cout<<"\nenter node to find:";
	cin>>d;
	 if(findnode(l,d)==1)
	 cout<<"found";
	 else
	 cout<<"no";
	return 0;
}
