//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int max_pre=0;
    int c=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    for(int i=0;i<n-1;i++)
    {
        if(l[i]>l[i+1])
        {
            c++;
            i++;
        }
    }
    cout<<c<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
