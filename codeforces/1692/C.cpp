//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n=8;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<n-1;j++)
        {
            if(s[i][j]=='#'&&s[i-1][j+1]=='#'&&s[i-1][j-1]=='#'&&s[i+1][j+1]=='#'&&s[i+1][j-1]=='#')
            {
                cout<<i+1<<" "<<j+1<<"\n";
                return;
            }
        }
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
