//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k,m;
    cin>>n>>m>>k;
    int l[n];
    for(int i =0;i<n;i++)
    {
        cin>>l[i];
    }
    sort(l,l+n);
    if(k==1)
    {
        cout<<n<<"\n";
        return;
    }
    int ans=0;
    bool slept[n]={0};
    for(int i=0;i<n;i++)
        slept[i]=0;
    int alarm=k;
    for(int i=0;i<=n-alarm;i++)
    {
        alarm++;
        if(!slept[i])
        {
            alarm--;
   // cout<<l[i+k]-l[i]<<"\n";
            while(i+k-1+k-alarm<n&&l[i+k-1+k-alarm]+1-l[i]<=m)
            {
                slept[i+k-1+k-alarm]=true;
                alarm--;
                ans++;
            }

        }

    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
