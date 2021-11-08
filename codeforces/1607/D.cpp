#include <iostream>
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
    string s;
    cin>>s;
    vector<int> r;
    vector <int> b;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='B')
        {
            r.push_back(l[i]);
            if(l[i]<0)
            {
                cout<<"NO"<<endl;
                return;
            }
        }else
        {
            b.push_back(l[i]);
            if(l[i]>n)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    //cout<<
    sort(r.begin(),r.end());
    sort(b.rbegin(),b.rend());
    for(int i=0;i<r.size();i++)
    {
        if(r[i]<=i)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=0;i<b.size();i++)
    {
        if(b[i]>n-i)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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
