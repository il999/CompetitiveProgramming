#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(k==0)
    {
        cout<<1<<endl;
        return;
    }
    bool thing=true;
    string news=s;
    reverse(s.begin(),s.end());
    if(news==s)
    {
        cout<<1<<endl;
    }else
    {
        cout<<2<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
