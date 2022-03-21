//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int total=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }

    sort(l,l+n);
    long long blue=l[0]+l[1];
        long long red=l[n-1];
    if(blue<red)
    {
        cout<<"YES"<<"\n";
        return;
    }
    for(int i=2;i<n-i;i++)
    {
        blue+=l[i];
        red+=l[n-i];

         if(blue<red)
        {
            cout<<"YES"<<"\n";
            return;
        }
    }
    cout<<"NO"<<"\n";
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
