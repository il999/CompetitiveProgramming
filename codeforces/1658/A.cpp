//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int c=0;
    int ans=0;
    int m=0;
    int w=0;
    int last=-1;
    for(int i=0;i<n;i++)
    {

         if(s[i]=='0')
        {
            if(last!=-1)
                ans+=max(0,(3-(i-last)));
            last=i;
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
