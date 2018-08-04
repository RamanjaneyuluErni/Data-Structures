#include <iostream>
using namespace std;
void swap(int *x,int *y){
    int *t;t=new int;
    *t=*x;*x=*y;*y=*t;
}

int main()
{
    int a,b;
    cout<<"enter a and b :"<<endl;
    cin>>a>>b;
    swap(&a,&b);
    cout<<"swapped values are : \n"<<a<<" "<<b;
    return 0;
}
