#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int l,r,k;
    cin>>l>>r>>k;
    if(l==1&&r==1)
    {
        cout<<"NO"<<endl;
        return;
    }
    int thing=r-l+1;
    int whatever=thing/2;
    if(thing%2==1&&!((l%2==0)&&r%2==0))
    {
        whatever++;
    }
    //cout<<"DSGHASD"<<whatever<<endl;
    if(k>=whatever||thing==1)
    {
        cout<<"YES"<<endl;
    }else
    {
        cout<<"NO"<<endl;
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
