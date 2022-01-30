#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    int ones=0;
    int zeros=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            ones++;
        }else
        {
            zeros++;
        }
    }
    if(n==2&&ones==1&&zeros==1)
    {
        cout<<"YES"<<endl;
    }else
    {
        cout<<"NO"<<endl;
    }
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
