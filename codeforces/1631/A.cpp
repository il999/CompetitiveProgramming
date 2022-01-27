#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{

    int n;
    cin>>n;
    int l1[n];
    int l2[n];
    for(int i=0;i<n;i++)
    {
        cin>>l1[i];
    }
    int thing;
     for(int i=0;i<n;i++)
    {
        cin>>l2[i];
        if(l1[i]<l2[i])
        {
            thing=l2[i];
            l2[i]=l1[i];
            l1[i]=thing;
        }
    }
    sort(l1,l1 +n);
    sort(l2,l2+n);
    cout<<l1[n-1]*l2[n-1]<<endl;
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
