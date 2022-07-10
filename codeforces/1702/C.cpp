//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
    vector<pair<int,int>> v;
      int n,k;

void solve()
{

    cin>>n>>k;

    int tp=0;
    map<int,int> m;
    map<int,int> m2;
    for(int i=0;i<n;i++)
    {
        cin>>tp;
        if(m.find(tp)==m.end())
        {
            m[tp]=(i);
        }
        m2[tp]=i;
    }
    sort(v.begin(),v.end());
    int a,b;

    while(k--)
    {
        cin>>a>>b;
      //  cout<<m[a]<<" "<<m2[b]<<" \n";
        if(m.find(a)==m.end()||m2.find(b)==m2.end())
        {
            cout<<"NO\n";
        }
        else if(m[a]<m2[b])
        {
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }

    }
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
