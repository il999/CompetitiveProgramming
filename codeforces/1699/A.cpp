//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    if(n&1)
    {
        cout<<-1<<"\n";

    }else
    {
        cout<<n/2<<" "<<n/2<<" "<<0<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
