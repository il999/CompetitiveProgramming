//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int one=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        if(l[i]==1)
        {
            one++;
        }
    }
    if(one!=1)
    {
        cout<<"NO"<<"\n";
        return;
    }

    for(int i=0;i<n;i++)
    {

        if(i>0&&l[i]-l[i-1]>1)
        {
            cout<<"NO"<<"\n";
            return;
        }

    }
    if(l[0]-l[n-1]>1)
    {
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<endl;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
