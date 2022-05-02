//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int a,b;
    cin>>a>>b;

    if(b%a==0)
    {
        cout<<1<<" "<<b/a<<endl;
    }else
    {
        cout<<0<<" "<<0<<endl;
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
