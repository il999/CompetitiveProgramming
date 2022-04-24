//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int amount[n+1]={0};
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        amount[l[i]]++;
    }
    sort(l,l+n);
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(amount[i]>2)
        {
            cout<<i<<"\n";
            return;
        }
    }
    cout<<-1<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
