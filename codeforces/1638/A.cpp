#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int rev=n*2;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];

    }
    int thing=0;

    for(int i=0;i<=n-1;i++)
    {
        if(l[i]==i+1)
        {
            thing=i+1;

        }else
        {
            i=n+1;
        }
    }

        for(int i=0;i<n;i++)
        {
            if(l[i]==thing+1)
            {
                rev=i;
            }
        }
        for(int i=0;i<thing;i++)
        {
            cout<<l[i]<<" ";
        }
        if(rev==n*2)
        {
            cout<<"\n";
            return;
        }
        for(int i=rev;i>=thing;--i)
        {
            cout<<l[i]<<" ";
        }
        for(int i=rev+1;i<n;i++)
        {
            cout<<l[i]<<" ";
        }
        cout<<"\n";
        return;



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
