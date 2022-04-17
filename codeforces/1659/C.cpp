//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    long long a,b;
    cin>>a>>b;
    long long l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    int pre[n+1];
    pre[n]=0;
    int c=0;
    for(int i=n-1;i>=0;i--)
    {
        pre[i]=l[i]+pre[i+1];
    }
    long long cost=l[0]*b;
    for(int i=1;i<n;i++)
    {
        if((l[i-1]-c)*b*(n-i)>=a*(l[i-1]-c))
        {
            cost+=a*(l[i-1]-c);
            c=l[i-1];
        }
        cost+=(l[i]-c)*b;
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

