//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    long long n,m;
    cin>>n>>m;
    cout<<m*(m+1)/2+m*n*(n+1)/2-m<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
