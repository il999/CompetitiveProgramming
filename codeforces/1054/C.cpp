//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int r[n];

    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>r[i];
    }
    int t[n];
    for(int i=0;i<n;i++)
        t[i]=(n-(l[i]+r[i]));
    for(int i=0;i<n;i++)
    {
        int cc=0;
        for(int j=0;j<i;j++)
        {
            if(t[i]<t[j])
            {
                l[i]--;
            }
        }
        for(int j=i;j<n;j++)
        {
            if(t[i]<t[j])
            {
                r[i]--;;
            }
        }
        if(0!=l[i])
        {
            cout<<"NO"<<"\n";
            return;
        }
        if(0!=r[i])
        {
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++) cout<<t[i]<<" ";
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
