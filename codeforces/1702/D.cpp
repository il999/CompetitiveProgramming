//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    string s;
    int  n;
    int skip[26];
    cin>>s;
    cin>>n;
    string  p=s;
    sort(s.begin(),s.end());
    long long cost=0;
    for(int i=0;i<26;i++) skip[i]=0;
    for(int i=0;i<s.size();i++)
    {
        cost+=s[i]-'a'+1;

    }
    for(int i=s.size()-1;i>=0;i--)
    {
        if(cost>n)
        {
            skip[s[i]-'a']++;
            cost-=(s[i]-'a'+1);

        }
    }
    for(int i=0;i<s.size();i++)

    {

        if(skip[p[i]-'a']==0)
        {
            cout<<p[i];
        }else
        {
            skip[p[i]-'a']--;
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
