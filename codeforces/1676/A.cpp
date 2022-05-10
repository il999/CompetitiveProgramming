//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{

    string s;
    cin>>s;
    int first=(s[0]-'0')+(s[1]-'0')+(s[2]-'0');
    int second=(s[3]-'0')+(s[4]-'0')+(s[5]-'0');
    if(first==second)
    {
        cout<<"YES"<<"\n";
    }else
    {
        cout<<"NO\n";
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
