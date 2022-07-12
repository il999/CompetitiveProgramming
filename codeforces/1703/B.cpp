//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int h[26];
    for(int i=0;i<26;i++) h[i]=0;
    int b=0;
    for(int i=0;i<n;i++)
    {
        if(h[s[i]-'A']==0)
        {
            b++;
            h[s[i]-'A']=1;
        }
        b++;
    }
    cout<<b<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}

