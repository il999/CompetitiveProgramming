//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int c=1;
    long long ans=0;
    for(int i=0;i<=n;i++)
    {
        if(s[i]==s[i+1])
        {
            c++;
        }else
        {
            if(i>n/2-1)
            {
                ans=c;
                break;
            }
            c=1;

        }

    }
    if(n%2==0)
    {
        if(ans%2==1)
        {
            ans--;
        }
        cout<<ans<<"\n";
    }else

    {
        cout<<ans<<"\n";
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
