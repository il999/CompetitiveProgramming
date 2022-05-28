//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int m=9;
    if(n<100)
    {
        cout<<n%10<<"\n";
        return;
    }
    while(n>0)
    {
        m=min(m,n%10);
        n/=10;
    }
    cout<<m<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
