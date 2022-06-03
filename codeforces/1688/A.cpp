//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int> v;
    while(n>0)
    {
        v.push_back(n%2);
        n/=2;
    }
    v.push_back(0);
    long long j=0;
    bool zero=false;
    bool one=false;
    int one2=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==1)
        {
            one2++;
        }
        if(v[i]==1&&!one)
        {
            j=(1<<(i));
            one=true;
           // cout<<v.size()-i<<"iiii\n";
        }
    }
    if(one2==1)
    {
        //cout<<"GSD";
        for(int i=0;i<v.size();i++)
    {
        if(v[i]==0)
        {
             j+=(1<<(i));
             break;
        }

    }
    }
    cout<<j<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}

