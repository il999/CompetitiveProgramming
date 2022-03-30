//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int w,h;
    cin>>w>>h;

    long long biggest[4];
    long long points[4];
    for(int j=0;j<4;j++)
    {

        int n;
        cin>>n;
        int first=-1;
        cin>>first;
        int thing=0;
        points[j]=first;
        biggest[j]=-1;
        for(int i=1;i<n;i++)
        {
            cin>>thing;
            biggest[j]=thing-first;
        }
    }
    long long ans=0;
    int coord=0;
    ans=max(ans,max(biggest[0],biggest[1])*h);
    ans=max(ans,max(biggest[2],biggest[3])*w);
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
