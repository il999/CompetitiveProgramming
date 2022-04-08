
//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    sort(l,l+n);
    int c=1;
    int m=1;
    for(int i=0;i<n-1;i++)
    {
        if(l[i]==l[i+1])
        {
            c++;
            m=max(c,m);
        }else

        {
            c=1;
        }
    }

    int ans=n-m;
    int thing=m;
    int co=0;

    long long past=0;
    while(ans>past)
    {
        past+=thing;
        thing*=2;

        co++;
    }

    cout<<co+ans<<"\n";
}
int main()
{
ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
