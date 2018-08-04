#include<iostream>
using namespace std;
int b[10][10],V[10];char a[10];
struct queue{
			int sice;
			int front;
			int rear;
			int ele[20];
           }q;

int dequeue(struct queue &q)
  {       
        if(q.front==-1)
              {cout<<"queue is empty\n";}
        else 
         {  
		    int t;
            t=q.ele[q.front];
            if(q.front==q.rear)
                  {
		              q.front=-1;q.rear=-1;
				   }
            else
               {
			         q.front=(q.front+1)%(q.sice);
			    }
            return(t);
	      }
   }
   
void enqueue(struct queue &q,int x)
    {
	     if((q.rear+1)%(q.sice)==q.front) cout<<"queue is full\n";
					
        else{
              if(q.rear==-1)
			        {
				        q.front=0;q.rear=0; 
					}
              else q.rear=(q.rear+1)%q.sice;
			  q.ele[q.rear]=x;
			}
    }
void printBFT(int v,int n)
{
	q.front=-1;q.rear=-1;q.sice=20;
	enqueue(q,v);V[v]=1;enqueue(q,-2);
	while(1)
	{
		int k=dequeue(q);
		if(k==-2)
		{
			cout<<endl;
			if(q.front==-1)break;
			enqueue(q,-2);
		}
		else
		{
			cout<<a[k]<<" ";
			for(int i=0;i<n;i++)
		  {
			if(b[k][i]!=0 && V[i]!=1)
		      {
				 enqueue(q,i);V[i]=1;
			  }
		  }
	    }
		
	}
}
void addedge(char c1,char c2,int n)
{
	int v,u;
	for(v=0;v<n;v++) if(a[v]==c1) break;if(v==n) return;
	for(u=0;u<n;u++) if(a[u]==c2) break;if(u==n) return;
	b[v][u]=1;b[u][v]=1;
	cout<<"edge added b/w "<<a[v]<<" and "<<a[u]<<endl;
}
int main()
{
	char c,c1,c2;int n;
	cout<<"enter no of vertices:";cin>>n;
	cout<<"enter vertices:";
	for(int i=0;i<n;i++) 
	{ 
	      cin>>a[i];V[i]=0;
		  for(int j=0;j<n;j++) b[i][j]=0;
	} 
	while(1)
	{
		cout<<"enter vertices to join(# to stop)\n";
		cin>>c1;if(c1=='#') break;cin>>c2;
		addedge(c1,c2,n);
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

 int v;
 cout<<"enter initial vertex:";cin>>v;
 printBFT(v,n); 
	return 0;
}

