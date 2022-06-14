//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
 vector<vector<int>> adj;
int ans1=0;
int child[300001];
int dp[300001];
int dfs(int u, bool seen[])
{
    if(adj[u].size()==1)
    {
        return 0;
    }
    for(int i=0;i<adj[u].size();i++)
    {
        if(!seen[adj[u][i]])
        {
            seen[adj[u][i]]=1;
            child[u]+=dfs(adj[u][i],seen)+1;
        }
    }
    return child[u];
}

int dfs2(int u, bool seen[])
{
    //cout<<u<<"\n";
    if(adj[u].size()==1)
    {
        return 0;
    }else if(adj[u].size()==2&&u!=0)
    {
        for(int i=0;i<2;i++)
        {
            if(!seen[adj[u][i]])
                dp[u]=max(child[adj[u][i]],0);
            seen[adj[u][i]]=1;
        }

    }else
    {
        int u1, v=-1;
       // cout<<"GDSGW";
        for(int i=0;i<adj[u].size();i++)
        {
            if(!seen[adj[u][i]])
            {
               seen[adj[u][i]]=true;
                if(v==-1)
                {
                    v=i;
                }else
                {
                    u1=i;
                }
            }

        }
        dp[u]=max(dfs2(adj[u][u1],seen)+child[adj[u][v]],dfs2(adj[u][v],seen)+child[adj[u][u1]]);

    }

    return dp[u];
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
        child[i]=0;
        dp[i]=0;
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
    }
    bool seen[n];
    for(int i=0;i<n;i++)
    {
        seen[i]=0;
    }
    seen[0]=true;
    dfs(0,seen);
    for(int i=1;i<n;i++)
    {
        seen[i]=0;
    }
    dfs2(0,seen);
    //cout<<child[2]<<"\n";

    cout<<dp[0]<<"\n";;
}
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
