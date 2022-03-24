//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    int thing=0;
    for(int i=0;i<n;i++)
    {
        cin>>thing;
        v.push_back(make_pair(thing,i+1));
    }
    sort(v.begin(),v.end());
    cout<<v[0].second<<" "<<v[n-1].second<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
