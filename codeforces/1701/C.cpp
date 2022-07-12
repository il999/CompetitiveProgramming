//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    ll n,m;
    cin>>n>>m;
    long long l[n];
    int a=0;
    for(int i=0;i<n;i++) l[i]=0;
    for(int i=0;i<m;i++)
    {
        cin>>a;
        a--;
        l[a]++;
    }
    sort(l,l+n);

    ll low=0;
    ll high=l[n-1];
    while(low<high)
    {
        ll mid=(low+high)/2;
        ll needed=0;
        ll space=0;
        for(int i=0;i<n;i++)
        {
            if(l[i]<mid)
            {
                space+=(mid-l[i])/2;
            }else
            {
                needed+=(l[i]-mid);
            }
        }
        if(space<needed)
        {
            low=mid+1;
        }else
        {
            high=mid;
        }

    }
    cout<<high<<"\n";
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
