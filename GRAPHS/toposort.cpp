#include<iostream>
using namespace std;
int b[10][10];
void coursesavailable(char a[10],int n)
{
	for(int i=0;i<n;i++)
	{  
	    int s=0;
		for(int j=0;j<n;j++) s=s+b[j][i];
	    if(s==0) cout<<a[i]<<" ";
	}
}
int isavailable(char a[10],int n,char c)
{
	int f=0;
	for(int i=0;i<n;i++)
	{  
	    int s=0;
		for(int j=0;j<n;j++) s=s+b[j][i];
		if(s==0 && c==a[i]) 
		{
			f=1;
			for(int k=0;k<n;k++) 
			{
			   b[k][i]--;if(b[i][k]==1)b[i][k]=0;
			}
		}
	}
	if(f==1) return 1;
	return 0;
}
int main()
{
	char a[10],c;int n;
	cout<<"enter no of vertices:";cin>>n;
	cout<<"enter vertices:";
	for(int i=0;i<n;i++) 
	   cin>>a[i];
	cout<<"enter :\n";
	cout<<"1 if the vertex is adjacent\n";
	cout<<"0 otherwise\n";
	for(int i=0;i<n;i++)
	{
	  for(int j=0;j<n;j++)
	  {
	  	cout<<"adjacency b/w "<<a[i]<<" and "<<a[j]<<endl;
	  	cin>>b[i][j];
	  }
    }
    cout<<"  ";
 for(int i=0;i<n;i++) 
	  cout<<a[i]<<" ";cout<<endl;
   for(int i=0;i<n;i++)
	{
	   cout<<a[i]<<" ";
	  for(int j=0;j<n;j++)
	  {
	  	cout<<b[i][j]<<" ";
	  }cout<<endl;
    }
  int coursecount=n;
  while(1)
  	{
	   cout<<"available courses\n";
  	   coursesavailable(a,n);
  	   cout<<"\nchoose course to do\n";cin>>c;
  	   if(isavailable(a,n,c)==0) cout<<"\nno chance to do\n";
  	   else 
		 {
		   coursecount--;
		   if(coursecount==0)
		   {
		   	 cout<<"successfully done all courses:";break;
		   }
	     }
    }
  
	return 0;
}

