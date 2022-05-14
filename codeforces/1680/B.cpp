//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m;
    cin>>n>>m;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int top=0;
    int ei,jay=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='R')
            {
                ei=i;
                jay=j;
                i=n;
                j=m;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<jay;j++)
        {
            if(s[i][j]=='R')
            {
                cout<<"NO"<<"\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
