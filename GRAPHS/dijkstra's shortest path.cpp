#include<iostream>
#include<cstring>
using namespace std;
char a[10],P[10],s,g;int b[10][10],D[10],V[10],n;
void print(char g,char s,char p[])
{
	char print[10];int i,k=0;
    while(g!=s)
    {
    	for(i=0;i<n;i++)
    	{
    		if(g==a[i]) 
			{
			  print[k]=g;k++;break;
		    }
	    }
		g=p[i];
	}
	cout<<s;
	for(i=k-1;i>=0;i--) cout<<"->"<<print[i];
}
int main()
{
	cout<<"no of vertices:";cin>>n;
	cout<<"enter vertices\n";
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<"enter edges -1 to stop\n";
	for(int i=0;i<n;i++)
	{
	  for(int j=0;j<n;j++) b[i][j]=0;
	}
	int u,v;
	while(1)
	{
		cin>>u;if(u==-1)break;cin>>v;
		cin>>b[u-1][v-1];
	}
     cout<<"  "; 
	 for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;  
   for(int i=0;i<n;i++)
	{
	  cout<<a[i]<<" ";
	  for(int j=0;j<n;j++) cout<<b[i][j]<<" ";
	  cout<<endl;
    }
 cout<<"enter source and goal:\n";
 cin>>s>>g;
 for(int i=0;i<n;i++) 
 {
    P[i]='0';// storing previous vertex ;
    V[i]=0; // storing visited or not
    if(a[i]==s) D[i]=0; 
    else D[i]=999; // storing distances from source; 
 }
 char cv=s;
 while(cv!=g)
 {
 	for(int i=0;i<n;i++)
 	{
 		if(a[i]==cv)
 		{
		   for(int j=0;j<n;j++)
 		  {
 			if(b[i][j]!=0)
 			{
 				V[i]=1; // updating visit of vertex
 				if(D[i]+b[i][j]<D[j]) 
 				{
 					P[j]=cv;D[j]=D[i]+b[i][j];// updating distance
				}
			 }
		  } 
	     }
	 }
	 cout<<cv<<" ";
	 int s,min=999;
	 for(int k=0;k<n;k++) if(D[k]<min && V[k]==0) { s=k;min=D[k];} 
	 cv=a[s];
}
 for(int i=0;i<n;i++) if(a[i]==g) {cout<<"\nprinting minimum path of lenth:"<<D[i]<<endl;break;}
 print(g,s,P);
 return 0;
}


