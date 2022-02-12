#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int a[n];
    int cost=n;
    int zeros=0;
    for(int i=0;i<n;i++)
    {


        cin>>a[i];
        if(a[i]==0)
        {
            zeros++;
        }
    }
    cost+=zeros;
    int pre[n+1];
    pre[0]=0;
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if(a[i-1]==0)
        {
            pre[i]++;
        }
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            ans+=(j-i+1)+(pre[j+1]-pre[i]);
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
