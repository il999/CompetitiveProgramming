//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int l2[n];
    for(int i=0;i<n;i++)
    {


        cin>>l[i];
        l2[i]=l[i];
    }

    if(n==1)
    {
        cout<<-1<<"\n";
        return;
    }else
    {
        sort(l2,l2+n);
        if(l[0]!=l[1])
        {
             cout<<"-1\n";
                return;
        }
        if(l[n-1]!=l[n-2])
        {
             cout<<"-1\n";
                return;
        }
        for(int i=1;i<n-1;i++)
        {

            if(l2[i]!=l2[i+1]&&l2[i-1]!=l2[i])
            {
                cout<<"-1\n";
                return;
            }
        }
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(l[i],i+1));
        }
        sort(v.begin(),v.end());
        int ans[n];
        int last=0;
        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                if(v[i].first!=v[i-1].first)
                {
                    ans[last]=v[i-1].second;
                    last=i;
                }else
                {
                    ans[i]=v[i-1].second;
                }
            }else
            {

            }
        }
        ans[last]=v[n-1].second;
        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";

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
