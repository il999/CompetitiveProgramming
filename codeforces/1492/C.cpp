//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    int alp[26][2];
    int t1[m];
    int t2[m];
    for(int i=0;i<26;i++)alp[i][0]=-1;
    int in=0;
    for(int i=0;i<n;i++)
    {
        if(in>m-1)
            break;
        if(s[i]==t[in])
        {
            t1[in]=i;
            in++;
        }

    }
    in=m -1;
    for(int i=n-1;i>=0;i--)
    {
        if(in<0)
            break;
        if(s[i]==t[in])
        {
            t2[in]=i;
            in--;
        }

    }

    int m1=-10000000;

    for(int i=1;i<m;i++)
    {
        m1=max(m1,t2[i]-t1[i-1]);
        //cout<<alp[t2[i]-'a'][1]<<" "<<alp[t1[i-1]-'a'][0]<<"\n";
    }
    cout<<m1<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
