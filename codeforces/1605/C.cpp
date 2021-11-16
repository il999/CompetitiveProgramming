#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int amoung;
    int min1=-1;
   
    int a[n+1];
    int b[n+1];
     b[0]=0;
    a[0]=0;
    for(int i=0;i<n;i++)
    {
      if(s[i]=='a')
      {
        a[i+1]=a[i]+1;
        b[i+1]=b[i];
      }else if(s[i]=='b')
      {
        a[i+1]=a[i];
        b[i+1]=b[i]+1;
      }else
      {
        a[i+1]=a[i];
        b[i+1]=b[i];
      }
    }
    for(int i=2;i<=n;i++)
    {
      if(a[i]-a[i-2]==2)
      {
        cout<<2<<endl;
        return;
      }
    }
    for(int i=3;i<=n;i++)
    {
      if(a[i]-a[i-3]==2)
      {
        cout<<3<<endl;
        return;
      }
    }
    for(int i=4;i<=n;i++)
    {
      if(a[i]-a[i-4]==2&&(b[i]-b[i-4]==1))
      {
        cout<<4<<endl;
        return;
      }
    }
    for(int i=7;i<=n;i++)
    {
      if(a[i]-a[i-7]==3&&b[i]-b[i-7]==2)
      {
        cout<<7<<endl;
        return;
      }
    }
    cout<<-1<<endl;
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