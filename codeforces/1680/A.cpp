//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int l,r,el,er;
    cin>>l>>r>>el>>er;
    int m=l+el;
    if(el>=l&&el<=r)
    {
        m=el;

    }
    if(r>=el&&r<=er)
    {
        m=min(m,max(el,l));
    }
    if(l>=el&&l<=er)
    {
        m=min(m,l);
    }
    cout<<m<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
