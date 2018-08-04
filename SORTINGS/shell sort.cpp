#include<iostream>
using namespace std;
int a[16]={1,9,2,10,3,11,4,12,5,13,6,14,7,15,8,16};
void shellsort(int k)
{
	while(k>=1)
	{
		int i=0;
		while(k+i!=15 && i<16)
		{
			if(a[i]>a[k+i]) swap(a[i],a[k+i]);i++;
		}
		k=k-2;
	}
}
int check()
{
	for(int i=0;i<15;i++){if(a[i]>a[i+1]) return -1;}
	return 1;
}
int main()
{
	int k;
	cout<<"elements before sorting\n";
	for(int i=0;i<=15;i++)cout<<a[i]<<" ";cout<<endl;
	cout<<"enter diminishing increment foctor:";cin>>k;
	while(1)
	{
		if(check()==1)break;
		shellsort(k);
	}
    cout<<"\nelements after sorting\n";
	for(int i=0;i<=15;i++)cout<<a[i]<<" ";
	return 0;
}
