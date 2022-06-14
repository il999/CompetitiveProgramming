//coding template
#include <bits/stdc++.h>
using ll =long long;
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
    int c1=0;
    for(int i=0;i<n-1;i++)
    {
        if(l[i]==l[i+1])
            c1++;
    }
    if(c1%2==0)
    {
        cout<<n-c1<<"\n";
    }else
    {
        cout<<n-c1-1<<"\n";
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
