#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int pos1,pos2;
void swap(int &a,int &b)
{
	int temp=a;a=b;b=temp;
}
void swap(char a[],char b[])
{
	char temp[10];
	strcpy(temp,a);strcpy(a,b);strcpy(b,temp);
}

void sort(int A[])
{
	if(A[0]>A[1])swap(A[0],A[1]);if(A[1]>A[2])swap(A[1],A[2]);
	if(A[0]>A[1])swap(A[0],A[1]);if(A[1]>A[2])swap(A[1],A[2]);
}
void merge(ifstream &fin1,ifstream &fin2,int n1,int n2,char of1[])
{
	ofstream fout;int i=0,j=0;int a=999,b=999;
	fout.open(of1,ios::app);
	fout<<endl<<n1+n2;cout<<"output "<<n1+n2<<endl;if(n1!=0)fin1>>a;if(n2!=0)fin2>>b;
	cout<<"taken a="<<a<<"\ntaken b="<<b<<endl;
	while(i<n1&&j<n2)
	{
		if(a>=b&&j<n2)
		{
			fout<<" "<<b;cout<<"output "<<b<<endl;j++;if(j<n2){fin2>>b;cout<<"taken b="<<b<<endl;}
		}
		else if(a<=b&&i<n1)
		{
			fout<<" "<<a;cout<<"output "<<a<<endl;i++;if(i<n1){fin1>>a;cout<<"taken a="<<a<<endl;}
		}
	}
	while(i<n1){fout<<" "<<a;cout<<"output "<<a<<endl;i++;if(i<n1){fin1>>a;cout<<"taken a="<<a<<endl;}}
	while(j<n2){fout<<" "<<b;cout<<"output "<<b<<endl;j++;if(j<n2){fin2>>b;cout<<"taken b="<<b<<endl;}}
	fout.close();
}
int main()
{
	ofstream fout;
	fout.open("sortinginput.txt",ios::trunc);
	int n=1,fileno=0,a[3],b[3],c,i,j,nop=0,n1,n2;
	cout<<"enter numbers to keep in file(-1 to stop):\n";
	cin>>n;fout<<n;
	while(1)
	{
		cin>>n;if(n==-1)break;
		fout<<endl<<n;
	}
	fout.close();
	fout.open("a1.txt",ios::trunc);fout.close();
	fout.open("a2.txt",ios::trunc);fout.close();
	fout.open("b1.txt",ios::trunc);fout.close();
	fout.open("b2.txt",ios::trunc);fout.close();
	ifstream fin("sortinginput.txt"),fin1,fin2;
	while(!fin.eof())
	{
		c=1;fin>>a[0];a[1]=999;a[2]=999;
		if(fileno==0)fout.open("a1.txt",ios::app);
		else fout.open("a2.txt",ios::app);
		fout<<endl;
		if(!fin.eof()){fin>>a[1];c++;}if(!fin.eof()){fin>>a[2];c++;}
		sort(a);
		if(c==1)
		{
			fout<<"1 "<<a[0];nop++;
		}
		else if(c==2)
		{
			fout<<"2 "<<a[0]<<" "<<a[1];nop++;
		}
		else
		{
			fout<<"3 "<<a[0]<<" "<<a[1]<<" "<<a[2];nop++;
		}
		fout.close();
		fileno=(fileno+1)%2;
	}
	fin.close();
	char pf1[10]="a1.txt",pf2[10]="a2.txt",of1[10]="b1.txt",of2[10]="b2.txt";
	fout.open(pf1,ios::app);fout<<endl<<"0";fout.close();
	fout.open(pf2,ios::app);fout<<endl<<"0";fout.close();
	while(nop>1)
	{
		fout.open(of1,ios::trunc);fout.close();
		fout.open(of2,ios::trunc);fout.close();
		int tag=0;pos1=1;pos2=1;
		fin1.open(pf1);fin2.open(pf2);
		while(1)
		{
			fin1>>n1;cout<<"taken from file 1 "<<n1<<endl;
			fin2>>n2;cout<<"taken from file 2 "<<n2<<endl;
			if(n1==0&&n2==0)break;cout<<"n1="<<n1<<" n2="<<n2<<endl;
			if(tag==0)merge(fin1,fin2,n1,n2,of1);
			else merge(fin1,fin2,n1,n2,of2);
			tag=(tag+1)%2;
		}
		fin1.close();fin2.close();
		fout.open(of1,ios::app);fout<<endl<<"\n0";fout.close();
		fout.open(of2,ios::app);fout<<endl<<"\n0";fout.close();
		if(nop%2==0)nop=nop/2;
		else nop=nop/2+1;
		swap(pf1,of1);swap(pf2,of2);
	}
	fin.open(pf1);fin>>n;
	fout.open("sortingoutput.txt");
	while(--n>=0){fin>>n1;fout<<n1<<endl;}
	return 0;
}
