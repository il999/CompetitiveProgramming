//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    multiset<int> a,b;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        while(x%2==0)
        {
            x/=2;
        }
        a.insert(x);
    }
    for(int i=0;i<n;i++)
    {
        cin>>x;
        b.insert(x);
    }
    while(!b.empty())
    {
        x=*b.rbegin();
        if(a.count(x))
        {
            a.erase(a.find(x));
            b.erase(b.find(x));

        }else
        {
            if(x==1)
            {
                cout<<"NO\n";
                return;
            }
            b.erase(b.find(x));
            b.insert(x/2);
        }
    }
    cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
