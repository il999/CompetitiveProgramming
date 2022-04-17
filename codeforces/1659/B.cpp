//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;int k;
    cin>>k;
    string s;
    cin>>s;
    if(k==0)
    {
        cout<<s<<"\n";
        for(int i=0;i<n;i++)
        {
            cout<<0<<" ";
        }
        cout<<"\n";
        return;
    }
    int be=k;
    int last=0;
    int l[n]={0};
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0'&&be%2==0)
        {
            k--;
            last=i;
            l[i]++;
        }
        if(s[i]=='1'&&be%2==1)
        {
            k--;
            last=i;
            l[i]++;
        }
        if(k==0)
        {
            break;
        }
    }
    bool thing=0;
    if(k>0)
    {
        if(k%2==1)
        {
            thing=true;
        }
        l[n-1]+=k;
    }

    for(int i=0;i<n;i++)
    {
        if(thing&&i==n-1)
        {
            cout<<0;
        }
        else if(i<=last)
        {
            cout<<1;
        }else
        {
            if(s[i]=='1')
            {
                if(be%2==0)
                {
                    cout<<1;
                }else
                {
                    cout<<0;
                }
            }else
            {
                if(be%2==0)
                {
                    cout<<0;
                }else
                {
                    cout<<1;
                }
            }
        }
    }

    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<l[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
