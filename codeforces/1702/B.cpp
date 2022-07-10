//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{


    string s;
    cin>>s;
    int n=s.size();
    int d=0;
    bool memorised[26];
    int ans=0;
    for(int i=0;i<26;i++) memorised[i]=0;
    for(int i=0;i<n;i++)
    {

        if(!memorised[s[i]-'a'])
        {
            if(d==0)
            {
                for(int j=0;j<26;j++) memorised[j]=0;
            }
            //cout<<"DGS";
            d++;
            //cout<<"GSD";
            memorised[s[i]-'a']=1;
            if(d==3)
            {
                ans++;

                d=0;
            }

        }
    }
    if(d>0)
    {
        ans++;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
