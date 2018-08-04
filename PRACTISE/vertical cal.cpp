#include <iostream>
using namespace std;
void cal(int space,int days,int month)
{
    int a[7][6]={};int p=0;int h=0;int y=0,i,j;
    y=1;
    i=0;j=0;
    //no of spaces required
    for(int i=0;i<space;i++)
    {
        a[p][h]=0;
        p++;
    }
    //inserting no of days
    for(int k=0;k<days;k++){
        a[p][h]=y;
        y++;p++;
        if(p==7){
            p=0;h++;
        }

    }cout<<endl;
    //printing no of days
    for(i=0;i<7;i++){
            if(i==0){
                cout<<"su   ";
            }
            if(i==1){
                cout<<"mo   ";
            }if(i==2){
                cout<<"tu   ";
            }if(i==3){
                cout<<"we   ";
            }if(i==4){
                cout<<"th   ";
            }if(i==5){
                cout<<"fr   ";
            }if(i==6){
                cout<<"sa   ";
            }
        for(j=0;j<6;j++){
                if(a[i][j]==31){
                    space=i;
                    space++;
                    if(space==7)
                    {space=0;}
                }
                if(days==30 && a[i][j]==30){
                    space=i;
                    space++;
                     if(space==7)
                    {space=0;}
                }
                if(a[i][j]==29 && month==2){
                    space=i;
                    space++;
                }
                if(a[i][j]==0){
                     cout<<"  ";
                  }
                else{
                     cout<<a[i][j]<<" ";
                    }
        }
        cout<<endl;
    }
    cout<<endl;
    month++;
    if(month==2){
        cout<<"feb";
        days=29;
        cal(space,days,month);
    }
    if(month==3){
        cout<<"mar";
        days=31;
        cal(space,days,month);
    }if(month==4){
        cout<<"apr";
        days=30;
        cal(space,days,month);
    }if(month==5){
        cout<<"may";
        days=31;
        cal(space,days,month);
    }if(month==6){
        cout<<"jun";
        days=30;
        cal(space,days,month);
    }if(month==7){
        cout<<"jul"<<endl;
        days=31;
        cout<<"space is "<<space;
        cal(space,days,month);
    }if(month==8){
        cout<<"aug";
        days=31;
        cal(space,days,month);
    }if(month==9){
        cout<<"sep";
        days=30;
        cal(space,days,month);
    }if(month==10){
        cout<<"oct";
        days=31;
        cal(space,days,month);
    }if(month==11){
        cout<<"nov";
        days=30;
        cal(space,days,month);
    }if(month==12){
        cout<<"dec";
        days=31;
        cal(space,days,month);
    }
}

int main()
{   int n=5,l=31,q=1;
    cout<<"2016 year calender"<<endl;
    cout<<endl;
    cout<<"jan";
    cal(n,l,q);
    return 0;
}
