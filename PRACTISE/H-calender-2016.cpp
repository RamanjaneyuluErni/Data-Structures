#include<iostream>
using namespace std;
int fun(int l){
    static int k=5;int j=0,i=1;
cout<<"SUN  MON  TUE  WED  THU  FRI  SAT"<<endl;
while(j<(5*k)){cout<<" ";j++;
}
while(i<=l)

{if(k%7==0)
 {cout<<endl;
   k=0;}
 if(i<10)
  {
    cout<<i<<"    ";}
   else
  {
    cout<<i<<"   ";}
   i++;k++;
}

cout<<endl;
cout<<"_____________________________________\n";
}
int main()
{ int n;
cout<<"january\n";fun(31);
cout<<" february\n";fun(29);
cout<<"march\n";fun(31);
cout<<"april\n";fun(30);
cout<<"may\n";fun(31);
cout<<"june\n";fun(30);
cout<<"july\n";fun(31);
cout<<"august\n";fun(31);
cout<<"september\n";fun(30);
cout<<"actober\n";fun(31);
cout<<"november\n";fun(30);
cout<<"december\n";fun(31);
return 0;
}
