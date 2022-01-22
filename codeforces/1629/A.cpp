#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> v;
    int thing;

    for(int i=0;i<n;i++)
    {
        cin>>thing;
        v.push_back(make_pair(thing,0));
    }
    for(int i=0;i<n;i++)
    {
        cin>>thing;
        v[i].second=thing;
    }
    sort(v.begin(),v.end());

  for(int i=0;i<n;i++)
    {
        if(v[i].first<=k)
        {
            k+=v[i].second;
        }
    }
    cout<<k<<endl;
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
