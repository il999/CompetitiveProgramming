//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int thing=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>b[i])
        {
            thing =a[i];
            a[i]=b[i];
            b[i]=thing;
        }
    }
    long long ans=0;
    for(int i=1;i<n;i++)
    {
        ans+=abs(a[i]-a[i-1])+abs(b[i]-b[i-1]);
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
