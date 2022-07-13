//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }

    ll ans=0;
    ll tempans=0;
    ll pre=0;
    for(int i=0;i<n;i++)
    {
        pre+=l[i]-k;
        tempans=0;
        for(int j=i+1;j<min(n,i+31);j++)
        {
            int t=l[j];
            for(int k=0;k<j-i;k++)
            {
                t/=2;
            }
            tempans+=t;
        }
        ans=max(ans,pre+tempans);
    }
    tempans=0;
    for(int j=0;j<min(n,31);j++)
        {
            int t=l[j];
            for(int k=0;k<j+1;k++)
            {
                t/=2;
            }
            tempans+=t;
        }

    cout<<max(ans,tempans)<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
