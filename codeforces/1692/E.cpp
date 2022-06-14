//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int s;
    cin>>s;
    int l[n];
    int act=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        act+=l[i];
    }
    if(act<s)
    {
        cout<<-1<<"\n";
        return;
    }
    vector<int> o1;
    vector<int> o2;
    if(act==s)
    {
        cout<<0<<"\n";
        return;
    }
    if(s==0)
    {
        cout<<0<<"\n";
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(l[i]==1)
            o1.push_back(i+1);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(l[i]==1)
            o2.push_back(n-i);
    }
    int ans=1e9;
    //cout<<o2[1]<<"\n";
    for(int i=0;i<act-s;i++)
    {
        if(i>0)
        {
            ans=min(o1[(act-s)-i-1]+o2[i-1],ans);
        }else
        {
            ans=o1[(act-s)-1];
        }
       // cout<<i<<" "<<ans<<"\n";
    }
      ans=min(o2[act-s-1],ans);
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
