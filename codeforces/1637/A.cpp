#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int max_sofar=0;
    int l[n];
    int l2[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        l2[i]=l[i];
    }
    sort(l2,l2+n);
    for(int i=0;i<n;i++)
    {
        if(l2[i]!=l[i])
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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
