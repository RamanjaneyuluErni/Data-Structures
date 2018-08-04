#include <iostream>
using namespace std;
int fact(int x){
    if(x==0){return 1;}
    else
    return x*fact(x-1);
}

int main()
{
    int n=0,j=0;
    cout<<"enter the num : \n";
    cin>>n;
    j=fact(n);
    cout<<j;
    return 0;
}
