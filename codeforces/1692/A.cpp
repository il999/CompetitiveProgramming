//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    int c1=0;
    if(a>n)
    {
        c1++;
    }
    if(b>n)
    {
        c1++;
    }
    if(c>n)
        c1++;
    cout<<c1<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
