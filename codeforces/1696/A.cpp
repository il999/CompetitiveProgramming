#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    int z;
    cin>>z;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    int m=l[0]|z;
    for(int i=1;i<n;i++)
        m=max(m,l[i]|z);
    cout<<m<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
