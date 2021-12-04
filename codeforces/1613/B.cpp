#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int l2[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];

    }
    bool present=false;
    int low=0;
    int search1=0;
    int high=n;
    int count1=0;
    int mid=0;
    sort(l,l+n,greater<int>());

    for(int i=0;i<n/2;i++)
    {
        cout<<l[i]<<" "<<l[n-1]<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
