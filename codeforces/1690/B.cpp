//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    long long a[n];
    long long b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    long long difference=-1;
    long long m=0;
    for(int i=0;i<n;i++)
    {
        if(b[i]==0)
        {
            m=max(a[i]-b[i],m);
            //nothing
        }else if(difference==-1)
        {
            if(a[i]-b[i]<0)
            {
                cout<<"NO\n";
                return;
            }else
            {
                difference=a[i]-b[i];
            }
        }else if(difference!=a[i]-b[i])
        {
            cout<<"NO\n";
            return;
        }
    }
    if(difference!=-1&&m>difference)
    {
        cout<<"NO\n";
        return;
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
