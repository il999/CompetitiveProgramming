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
    for(int i=0;i<n-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            if((c+1)%2==1)
            {
                s[i]=s[i+1];
                ans++;
                c=1;
            }else
            {
                 c=0;
            }


        }else
        {
            c++;
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
