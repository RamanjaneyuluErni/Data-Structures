#include<iostream>
#include<string.h>
#include<cstring>
#include<cstdlib>
using namespace std;
int x;
typedef
struct kdnode{
	 int *d;
	 string *str;
	 char *ch;
	 struct kdnode *lc;
	 struct kdnode *rc;
}*kptr;
void create(kptr &t,int a[],string s[],char c[],int k)
{
	if(t==NULL)
	{
		t=new kdnode;
		t->d=new int[k/3];
		for(int i=0;i<k/3;i++) t->d[i]=a[i];
		t->str=new string[k/3];
		for(int i=0;i<k/3;i++) t->str[i]=s[i];
		t->ch=new char[k/3];
		for(int i=0;i<k/3;i++) t->ch[i]=c[i];
        t->lc=NULL;
        t->rc=NULL;
	
	}
	cout<<"enter LC  (0 to continue):";
	cin>>x;
	if(x==0)
	{
      cout<<"enter "<<k/3<<" integers:\n";
      for(int i=0;i<k/3;i++)cin>>a[i];
      cout<<"enter "<<k/3<<" strings:\n";
      for(int i=0;i<k/3;i++)cin>>s[i];
      cout<<"enter "<<k/3<<" characters:\n";
      for(int i=0;i<k/3;i++)cin>>c[i];
	  create(t->lc,a,s,c,k);
    }
	cout<<"enter RC  (0 to continue):";
	cin>>x;
	if(x==0)
	{
	  cout<<"enter "<<k/3<<" integers:\n";
      for(int i=0;i<k/3;i++)cin>>a[i];
      cout<<"enter "<<k/3<<" strings:\n";
      for(int i=0;i<k/3;i++)cin>>s[i];
      cout<<"enter "<<k/3<<" characters:\n";
      for(int i=0;i<k/3;i++)cin>>c[i];
	  create(t->rc,a,s,c,k);
    }
}
void search(kptr &t,int a[],string s[],char c[],int k)
{
	
	if(t!=NULL)
	{
		search(t->lc,a,s,c,k);
		int i=0;
		while(i<k/3)
		{
	      if(t->d[i]==a[i] && strcmp(t->str[i].c_str(),s[i].c_str())==0 && t->ch[i]==c[i])
		       i++;
		  else break;
		}
		if(i==k/3) 
		{
			cout<<"found:\n";
			for(int i=0;i<k/3;i++)cout<<t->d[i]<<" ";
			cout<<endl;
			for(int i=0;i<k/3;i++) cout<<t->str[i]<<" ";
			cout<<endl;
			for(int i=0;i<k/3;i++)cout<<t->ch[i]<<" ";
			exit;
		}
	}
	if(t==NULL) return;
	search(t->rc,a,s,c,k);
}
int main()
{
   kptr t=NULL;
   int k,a[10];char c[10];string s[10];
   
   cout<<"enter no of keys(divisible by 3):";
   cin>>k;
   cout<<"enter "<<k/3<<" integers:\n";
   for(int i=0;i<k/3;i++)cin>>a[i];
   cout<<"enter "<<k/3<<" strings:\n";
   for(int i=0;i<k/3;i++)cin>>s[i];
   cout<<"enter "<<k/3<<" characters:\n";
   for(int i=0;i<k/3;i++)cin>>c[i];
   create(t,a,s,c,k);
   cout<<"enter key to search:\n";
   cout<<"enter "<<k/3<<" integers:\n";
   for(int i=0;i<k/3;i++)cin>>a[i];
   cout<<"enter "<<k/3<<" strings:\n";
   for(int i=0;i<k/3;i++)cin>>s[i];
   cout<<"enter "<<k/3<<" characters:\n";
   for(int i=0;i<k/3;i++)cin>>c[i];
   search(t,a,s,c,k);
   return 0;
}
