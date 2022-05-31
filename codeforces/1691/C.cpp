//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    long long ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='1')
        {
            ans+=10+(s[i+1]-'0');
        }else
        {
            ans+=(s[i+1]-'0');

        }

    }
   // cout<<ans<<"\n";
    int first=-1;
    int second=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            second=i;
            if(first==-1)
            {
                first=i;
            }
        }
    }
    //cout<<ans<<"\n";
    bool second1=false;
    if(k>=(n-1)-second&&second!=-1&&second!=n-1)
    {
        if(second==0)
        {
            ans+=1;
        }
        ans-=10;
        k-=(n-1-second);
        second1=true;
    }
    if(k>=first&&first!=-1&&first!=0&&!(first==second&&second1)&&first!=n-1)
    {
        ans-=1;

    }
    cout<<ans<<"\n";

}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
