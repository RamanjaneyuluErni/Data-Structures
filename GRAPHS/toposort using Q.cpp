#include<iostream>
using namespace std;
int b[10][10];
struct queue{
			int size;
			int front;
			int rear;
			char ele[20];
           }q;
char deque(struct queue &q)
{       
    if(q.front==-1)cout<<"Q is empty\n";
    else 
      {  
		char t=q.ele[q.front];
        if(q.front==q.rear)
        {
		  q.front=-1;q.rear=-1;
		}
        else q.front=(q.front+1)%(q.size);
	    return(t);
      }
}
   
void enque(struct queue &q,char x)
{
   if((q.rear+1)%(q.size)==q.front) cout<<"Q is full\n";
	else{
          if(q.rear==-1)
			{
			  q.front=0;q.rear=0; 
        	}
          else q.rear=(q.rear+1)%q.size;
		q.ele[q.rear]=x;
		}
}
    
void coursesavailable(char a[10],int n)
{
	cout<<"\navailable courses:";
	for(int i=0;i<n;i++)
	{  
	    int s=0;
		for(int j=0;j<n;j++) s=s+b[j][i];
		if(s==0)
		{
			 enque(q,a[i]);cout<<a[i]<<" ";
		 }
	}
}
void docourse(char a[10],int n)
{
	int i,j;
	while(1)
	{
	  if(q.front==-1) break;
	  char d=deque(q);
	  for(i=0;i<n;i++) if(a[i]==d) break;
	  for(int k=0;k<n;k++) 
	  {
	     b[k][i]--;if(b[i][k]==1) b[i][k]=0;
	   }
	  cout<<"\ncourse recently did:"<<d;
	  coursesavailable(a,n);
	}
}
int main()
{
	q.front=-1;q.rear=-1;q.size=20;
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
  coursesavailable(a,n);
  docourse(a,n);
  cout<<"\nsuccessfully done all courses:";
  return 0;
}

