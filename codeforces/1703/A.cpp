//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    string s;
    cin>>s;
    if(s[0]!='Y'&&s[0]!='y')
    {
        cout<<"NO\n";
        return;
    }
     if(s[1]!='E'&&s[1]!='e')
    {
        cout<<"NO\n";
        return;
    }
     if(s[2]!='S'&&s[2]!='s')
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}


