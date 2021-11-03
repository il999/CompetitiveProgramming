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
    int max1=l[0];
    for(int i=1;i<n;i++)
    {
        max1=max(max1,l[i]-l[i-1]);
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
