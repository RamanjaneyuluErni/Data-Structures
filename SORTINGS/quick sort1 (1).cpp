#;include<iostream>
using namespace std;
int n,c=0,a[30];
int partition(int low,int high)
{
	int p=a[low],l=low+1,h=high;
	while(l<=h)
	{
		while(a[l]<p) l++;
		while(a[h]>p) h--;
		if(l<h) 
		{
			int temp=a[l];a[l]=a[h];a[h]=temp;
		}
	}
	if(h<l)
	{
	  int temp=a[low];a[low]=a[h];a[h]=temp;	
	}
	return h;
}
void quicksort(int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(low,high);
		cout<<"elments after "<<++c<<" iteration:";
		for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;	
	    quicksort(low,j-1);
	    quicksort(j+1,high);
    }
}
int main()
{
	cout<<"enter no of elemnets:";cin>>n;
	cout<<"enter elemnts:\n";
	for(int i=0;i<n;i++) cin>>a[i];
    cout<<"elments before sorting:";
	for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
	int low=0,high=n-1;
	quicksort(low,high);
	cout<<"elemnets after sorting\n";
	for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
	return 0;
}
