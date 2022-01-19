#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int thing;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        cin>>thing;
        v.push_back(make_pair(thing,i));

    }
    sort(v.begin(),v.end());
    int count1=0;
    int beg=-1;
    int max1=-1;
    int max2=0;
    for(int i=0;i<n;i++)
    {

        if(v[i].first==v[i+1].first)
        {

            max2=min(v[i].second,v[i+1].second)+n-max(v[i].second,v[i+1].second);
            //cout<<v[i].first<<" max: " <<max2<<endl;

            max1=max(max1,max2);
        }
    }
    cout<<max1<<endl;
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

