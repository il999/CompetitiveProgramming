//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];

    }
    int f=n;
    int s=-1;
    int count1=0;
    int first=0;
    bool pos=true;
    for(int i=1;i<n;i++)
    {
        if(l[i]-l[i-1]==0)
        {
            count1++;

            if(i>s+2&&f!=n)
            {
                pos=false;
            }
            f=min(f,i);
            s=max(s,i-1);
        }

    }
    if(pos)
    {
        if(count1>2)
        {
            cout<<count1-2<<"\n";
        }else if(count1==2)
        {
            cout<<1<<"\n";
        }else
        {
            cout<<0<<"\n";
        }
    }else
    {
        cout<<s-f<<"\n";
    }
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
