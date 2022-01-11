#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];

    for(int i=0;i<n;i++)
    {
        cin>>l[i];

    }
    sort(l,l+n);
    int max1=0;
    int actual=l[n-1];

    for(int i=0;i<n;i++)
    {
        max1=max(abs(l[i]-actual),max1);
    }
    cout<<max1<<endl;
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
