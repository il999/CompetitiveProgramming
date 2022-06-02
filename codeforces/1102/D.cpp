//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int c[3];
    for(int i=0;i<3;i++)c[i]=0;
    for(int i=0;i<n;i++)
    {
        c[s[i]-'0']++;
    }
    // cout<<"DGSA";
    int in=0;
    while(c[0]<n/3)
    {
        if(s[in]!='0'&&c[s[in]-'0']>n/3)
        {
            c[s[in]-'0']--;
            s[in]='0';
            c[0]++;

        }
        in++;

    }

    in=n-1;
    while(c[2]<n/3)
    {
        if(s[in]!='2'&&c[s[in]-'0']>n/3)
        {
            c[s[in]-'0']--;
            s[in]='2';
            c[2]++;

        }
        in--;
    }
    in=0;
    //cout<<s<<"\n";
    while(c[1]<n/3&&in<n&&c[2]>n/3)
    {
        if(s[in]=='2')
        {
            s[in]='1';
            c[1]++;
            c[2]--;
        }
        in++;
    }
    in=n-1;
    while(c[1]<n/3&&in<n)
    {
        if(s[in]=='0')
        {
            s[in]='1';
            c[1]++;
            c[0]--;
        }
        in--;
    }
    cout<<s<<"\n";
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}

