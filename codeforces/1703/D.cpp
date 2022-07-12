//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s[n];
    map<string, int> m;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        m[s[i]]=1;
    }
    for(int i=0;i<n;i++)
    {
        string p="";
        string p2="";
        bool pri=0;
        for(int j=0;j<s[i].size();j++)
        {
            p+=s[i][j];
            p2="";
            for(int k=j+1;k<s[i].size();k++)
            {
                p2+=s[i][k];
            }
           // cout<<p<<" "<<p2<<"\n";
            if(m.find(p)!=m.end()&&m.find(p2)!=m.end())
            {

                pri=1;
                cout<<1;
                j=9;
            }

        }
        if(!pri)
        {
            cout<<0;
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
