//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int m;
    cin>>m;

    int q[m];
    for(int i=0;i<m;i++)
    {
        cin>>q[i];
    }
    int n;
    cin>>n;
        int l[n];
    int in=m-1;
    sort(q,q+m);
     for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    sort(l,l+n);
    int buy=0;
    long long cost=0;
    for(int i=n-1;i>=0;i--)
    {
        buy++;
        cost+=l[i];
        if(buy==q[0])
        {
            i-=2;
            buy=0;
        }
    }
    cout<<cost<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
