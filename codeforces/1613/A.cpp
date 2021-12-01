#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int x1,p1,x2,p2;
    cin>>x1>>p1;
    cin>>x2>>p2;
    int size1=1;
    int temp1=x1;
    while(x1>=10)
    {

        size1*=10;
        p1++;

        x1/=10;
    }
    x1=temp1;
    int size2=1;
    int temp=x2;
    while(x2>=10)
    {

        size2*=10;
        p2++;

        x2/=10;
    }
    x2=temp;
    if(p1>p2)
    {
        cout<<'>'<<endl;
    }else if(p2>p1)
    {
        cout<<'<'<<endl;
    }else
    {
        if(size2>size1)
        {
            x1*=(size2/size1);
        }else
        {
            x2*=(size1/size2);
        }
        if(x1>x2)
        {
            cout<<'>'<<endl;
        }else if(x2>x1)
        {
            cout<<'<'<<endl;
        }else
        {
            cout<<'='<<endl;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
