//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    long long n;
    cin>>n;
    long long round=1;
    while(round*10<=n)
    {
        round*=10;
    }
    cout<<n-round<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
