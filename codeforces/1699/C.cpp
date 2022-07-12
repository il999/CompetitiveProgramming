//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
const int MOD=1e9+7;
void solve()
{
    int n;
    cin>>n;
    int a[n];
    int loc[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        loc[a[i]]=i;
    }
    int space[n+1];
    space[0]=0;
    int l,r;
     l=loc[0];
     r=loc[0];
    long long ans=1;
    for(int i=1;i<n;i++)
    {
        if(loc[i]<l)
        {
            space[i]=space[i-1]+l-loc[i];
            l=loc[i];

        }else if(loc[i]>r)
        {
            space[i]=space[i-1]+loc[i]-r;
            r=loc[i];
        }else
        {
          //  cout<<r-l-i<<" "<<i<<" ghhh\n";
            ans=(ans*(r-l-i+1))%MOD;
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
