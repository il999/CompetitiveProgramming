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

    int zero=0;
    int same=0;
    for(int i=0;i<n;i++)
    {
        if(l[i]==0)
        {
            zero++;
        }
        if(i<n-1&&l[i]==l[i+1])
        {
            same=1;
        }
    }
    if(zero==0)
    {
        cout<<n+1-same<<"\n";
    }else
    {
        cout<<n-zero<<"\n";
    }
}
int main()
{
 //   ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
