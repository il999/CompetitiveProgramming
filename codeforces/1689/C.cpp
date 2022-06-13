//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
 vector<vector<int>> adj;
int ans1=0;
int dist[300001];
void dfs(int u, bool seen[])
{
    for(int i=0;i<adj[u].size();i++)
    {
        if(!seen[adj[u][i]])
        {
            dist[adj[u][i]]=dist[u]+1;
            seen[adj[u][i]]=true;
            dfs(adj[u][i],seen);
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    adj.clear();
    vector<int> te;
    for(int i=0;i<n;i++)
    {
        adj.push_back(te);
    }
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(adj[0].size()==1)
    {
        cout<<max(0,n-2)<<"\n";
        return;
    }else
    {
        dist[0]=0;
        bool seen[n];
        for(int i=0;i<n;i++)
        {
            seen[i]=0;
        }
        seen[0]=true;
        dfs(0,seen);
        int ans=1e9;
        for (int i=0;i<n;i++) {
            if (2*dist[i]+1+(adj[i].size()-1+(!i)) < ans && adj[i].size()+(!i) < 3) {
                ans = 2*dist[i]+1+(adj[i].size()-1+(! i));
                //cout<<n-ans<<" "<<i<<"\n";

            }
        }
        cout << n-ans << "\n";
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
