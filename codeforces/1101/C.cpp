//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;

    int m=0;
    vector<pair<int,int>> v;
    int x,y;
    vector<pair<int,int>> v2;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        v.push_back( make_pair(x,y));
        v2.push_back( make_pair(x,y));
        m=max(y,m);
    }
    sort(v.begin(),v.end());
    int lm=-1;
    int ans=-1;
int     ansx=0;
    int ansy=0;
    for(int i=0;i<n;i++)
    {
        if(v[i].first>lm&&lm!=-1)
        {
            ans=0;
            break;
        }

            lm=max(lm,v[i].second);

    }

    if(ans==-1)
    {
        cout<<-1<<"\n";
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(v2[i].second<=lm)
        {
            cout<<1<<" ";
        }else
        {
            cout<<2 <<" ";
        }
    }

    cout<<"\n";


}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
