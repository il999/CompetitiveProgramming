//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;

    string s;
    cin>>s;
    n=s.size();
    int c=1;
    bool tr=true;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            c++;
        }else if(c==1)
        {
            tr=false;
        }else
        {
            c=1;
        }
    }
    if(c==1)
        tr=false;
    if(tr)
    {
        cout<<"YES"<<"\n";
    }else
    {
        cout<<"NO"<<"\n";
    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
