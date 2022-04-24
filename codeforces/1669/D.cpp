//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    bool first=true;
    bool second=true;
    string samp="";
    bool different=false;
    for(int i=0;i<n;i++)
    {
        if(s[i]!='W')
        {
            samp+=s[i];
            if(samp.size()>1&&samp[samp.size()-2]!=s[i])
            {
                different=true;
            }
        }else if(samp.size()!=0)
        {

            if(!different)
            {
                cout<<"NO"<<"\n";
                return;
            }
            different=false;
            samp="";
        }

    }
    if(samp.size()>0&&!different)
    {

        cout<<"NO\n";
        return;
    }
    cout<<"YES"<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
