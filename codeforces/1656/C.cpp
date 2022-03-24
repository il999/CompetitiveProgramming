
//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    sort(l,l+n);
    bool thing=false;
    int place=0;
    for(int i=0;i<n;i++)
    {
        if(l[i]==1)
        {
            thing=true;
            place=i;
        }
    }
    if(!thing)
    {
        cout<<"YES"<<"\n";
        return;
    }
    int last=0;
    for(int i=1;i<n;i++)
    {
        if(l[i]-l[i-1]==1)
        {
            cout<<"NO"<<"\n";
            return;
        }

    }
    cout<<"YES"<<"\n";

}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
