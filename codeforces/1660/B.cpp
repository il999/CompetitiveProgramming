//coding template
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
    if(n==1&&l[0]==1)
    {
        cout<<"YES"<<"\n";
        return;
    }
    if(n==1&&l[0]!=1)
    {
        cout<<"NO"<<"\n";
        return;
    }
    if(l[n-1]-l[n-2]<=1)
    {
        cout<<"YES"<<"\n";
    }else
    {
        cout<<"NO"<<"\n";
    }
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
