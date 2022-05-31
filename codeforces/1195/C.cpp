//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    long long a[n];
    long long b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    long long dp[n+1][3];
    dp[0][0]=0; dp[0][1]=0; dp[0][2]=0;
    for(int i=0;i<n;i++)
    {
        dp[i+1][0]=max(max(dp[i][1]+a[i],dp[i][2]+a[i]),a[i]);
        dp[i+1][1]=max(max(dp[i][0]+b[i],dp[i][2]+b[i]),b[i]);
        dp[i+1][2]=max(dp[i][0],dp[i][1]);
    }
    cout<<max(dp[n][0],dp[n][1])<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);


        solve();
}
