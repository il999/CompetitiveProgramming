//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;

    int m;
    cin>>n>>m;
    int cost=m*26;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int temp=0;;
    for(int i=0;i<n;i++)
    {

        for(int j=i+1;j<n;j++)
        {

            for(int k=0;k<m;k++)
            {
                temp+=abs((s[i][k])-(s[j][k]));
            }

           // cout<<temp<<"\n";
            cost=min(temp,cost);
            temp=0;
        }

    }
    cout<<cost<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
