//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    sort(l,l+n);
    long long c=0;
    int last=0;
    for(int i=0;i<n-1;i++)
    {
        c+=(l[i]+1)+l[i]-last;
        last=l[i];

    }
    c+=(l[n-1]-l[0])+1;


    c+=l[n-1]-l[n-2];

    //cout<<c<<"\n";
    if(c<=m)
    {
        cout<<"YES\n";
    }else
    {
        cout<<"NO\n";
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
