//coding template
#include <bits/stdc++.h>
using ll =long long;
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
    int c=0;
    while(n--)
    {
        int p;
        cin>>p;
        string s;
        cin>>s;
        int up=0;
        for(int i=0;i<p;i++)
        {
            if(s[i]=='D')
            {
                up++;
            }else
            {
                up--;
            }
        }
        l[c]+=up;
        if(l[c]>9)
        {
            l[c]-=10;
        }else if(l[c]<0)
        {
            l[c]=9+l[c]+1;
        }
        cout<<l[c]<<" ";
        c++;
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}

