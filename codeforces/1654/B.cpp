#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    int alpha[26]={0};
    for(int i=0;i<n;i++)
    {
        alpha[s[i]-'a']++;
    }
    int pre=0;
    for(int i=0;i<n;i++)
    {
        if(alpha[s[i]-'a']==1)
        {
            pre=i;
            break;
        }else
        {
            alpha[s[i]-'a']--;
        }
    }
    for(int i=pre;i<n;i++)
    {
        cout<<s[i];
    }
    cout<<"\n";
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
