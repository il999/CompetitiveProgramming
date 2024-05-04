#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;
const int maxn = 301;
int ans=0;
int timer=1;
int root(int v,vector<int>&par) {
    return v == par[v] ? v : par[v] = root(par[v],par);
}
void unite(int a, int b,vector<int>& par,vector<int>& sz) {
    a = root(a,par), b = root(b,par);
    if (a == b) {
        return;
    }
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
}
// comments are for articulation point code
void tarjan(int v, int p,vector<int>& val ,vector<int>& low,vector<vector<int>>& adj,vector<array<int,2> >& bridges,vector<int>& par,vector<int>& sz) {
    val[v] = low[v] = timer++;
    // int children = 0;
    for (auto to : adj[v]) {
        if (to == p) {
            continue;
        }
        if (!val[to]) {
            tarjan(to, v,val,low,adj,bridges,par,sz);
            low[v] = min(low[v], low[to]);
            // if (low[to] >= val[v] && p != -1)
            //   IS_ARTICULATION_POINT(v);
            // ++children;
            if (low[to] > val[v]) {
                bridges.push_back({v, to});
            } else {
                unite(v, to,par,sz);
            }
        } else {
            low[v] = min(low[v], val[to]);
        }
    }
    // if (p == -1 && children > 1)
    //   IS_ARTICULATION_POINT(v);
}
int t =1;
void dfs(int u, int last, vector<vector<int> >& adj,vector<bool>& visited){
    for(int to:adj[u]){
        if(visited[to]) continue;
        visited[to]=true;
        dfs(to,u,adj,visited);
        t++;
    }

}
void solve(){
    int n,m,c;
    cin>>n>>m>>c;

    int a,b;
    vector<int> low(n+1),val(n+1),par(n+1),sz(n+1);
   // int timer = 1;
    vector<vector<int > > adj(n+1), g(n+1);
    vector<bool> artiPoint(n+1);
    vector<array<int, 2>> bridges;

    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited2(n+1);
    t=1;
    visited2[1]=true;
    dfs(1,-1,adj,visited2);
    bool connected=false;
    if(t==n) connected=true;

    ans=n*n+c*n;
    int numofit=0;
    for(int i=1;i<=n;i++) {
        if(low[i]==0) {
            timer = 1;
            numofit++;
            tarjan(i, -1, val, low, adj, bridges, par, sz);
        }

    }
    if(numofit==1) {


        for (array<int, 2> br: bridges) {
            vector<bool> vis(n + 1);
            vis[br[0]] = 1;
            vis[br[1]] = 1;
            t = 1;
            dfs(br[0], br[1], adj, vis);
            int tp = t;
            t = 1;
            dfs(br[1], br[0], adj, vis);

            ans = min(ans, t * t + tp * tp);
        }
    }
    if(bridges.empty()&&connected){
        cout<<"-1\n";
        return;
    }

    if(!connected){

        vector<int> cons;
        cons.push_back(0);
        vector<bool> visited(n+1);
        for(int i=1;i<=n;i++){
            if(visited[i]) continue;
            t=1;
            visited[i]=true;
            dfs(i,-1,adj,visited);
            cons.push_back(t);
        }
        int toadd=c*(cons.size()-2);
        bridges.push_back({0,0});
        //cout<<cons[1]<<" "<<cons[2]<<" "<<ans<<"\n";
        for( array<int,2> br : bridges){
            // cerr  << br[0] << " " << br[1] << "\n";
            vector<bool> visited(n+1);
            visited[br[0]]=true;
            visited[br[1]]=true;
            t=1;
            int tp=0;
            int changed=-1;
            if(br[0]!=0) {
                dfs(br[0], br[1], adj, visited);
                tp = t;
                t=1;
                dfs(br[1], br[0], adj, visited);
                //int changed = -1;
                for (int i = 0; i < cons.size(); i++) {
                    if (cons[i] == tp + t) {
                        changed = i;
                        cons[i] = tp;
                        cons.push_back(t);
                    }
                }
            }

            vector<vector<int> > dp(cons.size()+1,vector<int>(n/2+2,1e9));
            dp[0][0]=0;
            for(int i=1;i<=cons.size();i++){
                for(int j=cons[i];j<=n/2+1;j++){
                    dp[i][j]=dp[i-1][j];
                    dp[i][j]=min(dp[i][j],dp[i-1][j-cons[i]]+1);
                    //  cout<<dp[i][j]<<" ooga\n";
                    int szcons=cons.size();
                    // cout<<dp[i][j]<<" "<<i<<" "<<j<<" "<<dp[i][j]*dp[i][j]+(n-dp[i][j])*(n-dp[i][j])+c*(szcons-2)<<"\n";
                    if(dp[i][j]>=1e9) continue;
                    // cerr << br[0] << " " << br[1] << " " << j << "\n";
                    // cerr << ans << "\n";
                    ans= min(ans,j*j+(n-j)*(n-j));
                    // cerr << ans << "\n";
                }
            }
            if(br[0]!=0) {
                cons[changed] = tp + t;
                cons.pop_back();
            }
        }



        cout<<ans+toadd<<"\n";
        return;
    }
    cout<<ans<<"\n";
}
signed main() {
    int t;
    cin>>t;
    while(t--)
        solve();
}
