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


    cout<<l[n-1]-l[0]<<endl;
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
