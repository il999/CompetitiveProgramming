//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int ans[m];
    for(int i=0;i<m;i++)
    {
        ans[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='U'&&i%2==0)
            {
                ans[j]++;
            }
            if(s[i][j]=='L')
            {
                if(j-i>=0)
                {
                    ans[j-i]++;
                }
            }
            if(s[i][j]=='R')
            {
                if(j+i<=m)
                {
                    ans[j+i]++;
                }
            }


        }
    }
    for(int i=0;i<m;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
