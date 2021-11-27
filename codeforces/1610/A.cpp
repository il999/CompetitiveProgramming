#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x,y;
    cin>>x>>y;
    if(x==1&&x==y)
    {
        cout<<0<<endl;
        return;
    }
   if(x==1||y==1)
   {
       cout<<1<<endl;
   }else
   {
       cout<<2<<endl;
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

