#include <iostream>

using namespace std;
//13
int notmain(int pos2,int count1){
    count1=0;
    if(pos2==5||pos2==1){
        count1=2;
    }else if(pos2==4||pos2==2){
        count1=1;

}
return count1;
}
int main()
{
    int pos1;
    int pos2;
    int r1[5][5];
    int count1=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++){


        cin>>r1[i][j];

        if(r1[i][j]==1){
            pos1=i+1;
            pos2=j+1;

        }
    }
    }
    count1+=notmain(pos2,count1);

    count1+=notmain(pos1,count1);
    cout<<count1;

    }



