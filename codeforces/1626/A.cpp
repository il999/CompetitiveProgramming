#include <iostream>

using namespace std;
void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    int l[26];
    for(int i=0;i<26;i++)
    {
        l[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        l[s[i]-'a']++;
    }

    for(int i=0;i<26;i++)
    {
        for(int j=0;j<l[i];j++)
        {
            cout<<char('a'+i);
        }
    }
    cout<<endl;
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
