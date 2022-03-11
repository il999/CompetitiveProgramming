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
    for(int i=0;i<n-1;i++)
    {

        for(int j=0;j<m-1;j++)

        {
            int c1=0;
            if(s[i][j]=='1')
                c1++;
            if(s[i+1][j]=='1')
                c1++;
            if(s[i][j+1]=='1')
                c1++;
            if(s[i+1][j+1]=='1')
                c1++;
            if(c1==3)
            {
                cout<<"NO"<<"\n";
                return;;
            }
        }
    }
    cout<<"YES"<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
