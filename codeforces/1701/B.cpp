//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    cout<<2<<"\n";
    bool done[n+1];
    for(int i=0;i<=n;i++) done[i]=0;
    for(int i=1;i<=n;i+=2)
    {
        for(int j=i;j<=n;j*=2)
        {
            cout<<j<<" ";
            done[j]=true;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!done[i])
        {
            cout<<i<<" ";
        }
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
