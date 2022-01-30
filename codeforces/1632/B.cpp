#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int e=1;
    int ans=0;
    while(e*2<n)
    {
        e*=2;
    }
    for(int i=e-1;i>=0;i--)
    {
        cout<<i<<" ";
    }
    cout<<e<<" ";
    for(int i=n-1;i>e;i--)
    {
        cout<<i<<" ";
    }
    cout<<endl;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
