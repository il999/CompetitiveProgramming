#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    string ss=s;
    sort(ss.begin(),ss.end());
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=ss[i])
        {
            v.push_back(i+1);
        }
    }
    if(v.size()>0)
    {
        cout<<1<<endl;
        cout<<v.size()<<" ";
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }else
    {
        cout<<0<<endl;
    }
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
