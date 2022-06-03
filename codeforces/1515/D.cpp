//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l,r;
    cin>>l>>r;
    int sr[r+1];
    int sl[l+1];
    for(int i=0;i<l;i++)
    {
        cin>>sl[i];
    }
    sort(sl,sl+l);
    for(int i=0;i<r;i++)
    {
        cin>>sr[i];
    }
    sort(sr,sr+r);
    int pairs=0;
    int in=0;
    for(int i=0;i<l;i++)
    {
        while(in<r-1&&sr[in]<sl[i])
        {
            in++;
        }
        if(in<r&&sr[in]==sl[i])
        {
            sl[i]=-1;
            sr[in]=-1;
            in++;
            pairs++;
        }
    }

    sort(sl,sl+l);
    sort(sr,sr+r);
    int oripair=pairs;
     int ans=0;
    if(r>l)
    {
        int temp=r;
        for(int i=0;i<temp-1;i++)
        {
            //cout<<sr[i]<<" "<<sr[i+1]<<"\n";
            if(sr[i]!=-1&&r>l&&sr[i]==sr[i+1])
            {
                pairs++;
                sr[i]=-1;
                sr[i+1]=-1;
                r-=2;
               // cout<<"DSG";
                ans++;
            }
        }
    }else
    {
        int temp=l;
        for(int i=0;i<temp-1;i++)
        {
            if(sl[i]!=-1&&l>r&&sl[i]==sl[i+1])
            {
                pairs++;
                sl[i]=-1;
                sl[i+1]=-1;
                l-=2;
                ans++;
            }
        }
    }
       //cout<<ans<<"\n";

    if(l==r)
    {
        cout<<ans+(n/2-pairs)<<"\n";
    }else if(l>r)
    {
        cout<<ans+((l-r)+r-oripair)<<"\n";
    }else
    {
         cout<<ans+((r-l)+l-oripair)<<"\n";
    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
