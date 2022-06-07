//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int s[n];
    int f[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
        cin>>f[i];
    int d[n];
    int time_delay=0;
    d[0]=f[0]-s[0];
    for(int i=1;i<n;i++)
    {
        if(s[i]>f[i-1])
        {
            d[i]=f[i]-s[i];
        }else
        {
            d[i]=f[i]-f[i-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<d[i]<<" ";
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
