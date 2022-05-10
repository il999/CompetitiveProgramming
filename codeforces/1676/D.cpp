//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m;
    cin>>n>>m;
    int l[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>l[i][j];
        }
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            long long temp=l[i][j];
            int next=1;
            for(int k=i-1;k>=0;k--)
            {
                if(j-next>=0)
                {
                    temp+=l[k][j-next];
                }
                if(j+next<m)
                {
                    temp+=l[k][j+next];
                }
                next++;
            }
            next=1;
            for(int k=i+1;k<n;k++)
            {
                if(j-next>=0)
                {
                    temp+=l[k][j-next];
                }
                if(j+next<m)
                {
                    temp+=l[k][j+next];
                }
                next++;
            }
           //cout<<temp<<" "<<i<<" "<<j<<"\n";
            ans=max(temp,ans);

        }
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
