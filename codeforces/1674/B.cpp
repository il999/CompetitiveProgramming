//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int ans=(s[0]-'a')*25;
    if(s[1]-'a'<s[0]-'a')
    {
        cout<<ans+(s[1]-'a'+1)<<endl;
    }else
    {
        cout<<ans+(s[1]-'a')<<endl;
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
