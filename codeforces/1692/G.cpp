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
    int l[n];
    for(int i=0;i<n;i++)
        cin>>l[i];
    int ans=0;
    bool pos[n];
    for(int i=0;i<n;i++)
    {
        pos[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(l[i]>=l[i+1]*2)
        {
            pos[i+1]=1;
        }
    }
    int last=0;
    for(int i=0;i<n;i++)
    {
        if(pos[i])
            last=i;
        if(i>=k&&i-last>=k)
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
