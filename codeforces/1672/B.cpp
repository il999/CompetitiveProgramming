//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    if(s[n-1]!='B')
    {
        cout<<"NO\n";
        return;
    }
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A')
        {

            count1++;
        }else
        {

            count2++;
        }
        if(count1<count2)
        {
            cout<<"NO\n";
            return;
        }
    }


    cout<<"YES\n";
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
