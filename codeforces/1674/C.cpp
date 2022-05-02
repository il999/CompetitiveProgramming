//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    string t;
    cin>>s;
    cin>> t;
    bool p=false;
    for(int i=0;i<t.size();i++)
    {
        if(t[i]=='a')
        {
            p=true;
        }
    }
    if(t.size()>1&&p)
    {
        cout<<-1<<endl;
        return;
    }

        if(t.size()==1&&p)
        {
            cout<<1<<endl;
            return;
        }

            long long ans=1;
            for(int i=0;i<s.size();i++)
            {
                ans*=2;
            }
            cout<<ans<<endl;



}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
