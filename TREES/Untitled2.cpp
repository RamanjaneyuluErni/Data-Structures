#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef
struct tnode{
	int data;
	tnode *lc;
	tnode *rc;
}*tptr;
int find_pos(int n,int )
void construct(tptr &t,int in[],int pre,int i,int n,int p)
{
	
	if(t==NULL)
	{
		t=new tnode;
		t->lc=NULL;
		t->rc=NULL;
		t->data=pre[p];
		construct(t->lc,in,pre,)
	}
}
int main()
{
	int pre[]={};
	int in[]={};
	tptr t=NULL;
	construct(t,pre,in,0,pre.size(),0);
	return 0;
}
