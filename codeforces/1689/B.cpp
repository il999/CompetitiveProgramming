//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];

    vector<pair<int,int>> a;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];

    }
    if(n==1)
    {
        cout<<-1<<"\n";
        return;
    }
    int ans[n];
    bool p[n+1]={0};
    p[0]=true;
    for(int i=0;i<n;i++)
    {
        bool done=false;
        if(l[i]!=i+1)
        {
            for(int j=1;j<=n;j++)
            {
                if(!p[j])
                {
                    ans[i]=j;
                    p[j]=true;
                    done=true;
                    break;
                }
            }
        }else
        {
            for(int j=1;j<=n;j++)
            {
                if(!p[j]&&j!=i+1)
                {
                    ans[i]=j;
                    p[j]=true;
                    done=true;
                    break;
                }
            }
        }
        if(!done)
        {
            int temp=0;
            temp=ans[i-1];
            ans[i]=ans[i-1];
            ans[i-1]=i+1;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
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
