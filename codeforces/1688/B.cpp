//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int cost[n];
    int odds=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        if(l[i]&1)
            odds++;
        cost[i]=0;
        while(l[i]>0)
        {
            if(l[i]%2==1)
            {
                break;
            }
            l[i]/=2;
            cost[i]++;

        }
    }
    sort(cost,cost+n);
    long long ans=0;
    bool odd3=0;
    for(int i=n-1;i>=0;i--)
    {

        if(cost[i]==0)
        {
            odd3=true;
        }
        if(odds>0&&cost[i]>0)
        {
            odds--;
            ans++;
            cost[i]=0;
        }

    }
    sort(cost,cost+n);
     if(!odd3)
     {
         ans+=cost[0];
     }

    for(int i=1;i<n;i++)
    {
        if(cost[i]>0)
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
