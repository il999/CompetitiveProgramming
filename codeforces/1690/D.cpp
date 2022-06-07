//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    string s;
    cin>>s;
    int pre[n+1];

    pre[0]=0;
    for(int i=0;i<n;i++)
    {
        pre[i+1]=pre[i];
        if(s[i]=='W')
        {
            pre[i+1]++;
        }
    }
    int cost=1e9+7;
    for(int i=k-1;i<n;i++)
    {
        cost=min(cost,pre[i+1]-pre[i-k+1]);
    }
    cout<<cost<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
