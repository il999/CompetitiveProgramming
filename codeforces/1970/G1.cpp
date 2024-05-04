#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
void dfs(int u, vector<vector<int> >& v, int last,int n,vector<int>& sz){
    for(int to :v[u]){
        if(to==last) continue;
        dfs(to,v,u,n,sz);
        sz[u]+=sz[to];
    }
  //  cout<<sz[u]*sz[u]+(n-sz[u])*(n-sz[u])<<"\n";
    ans=min(ans,sz[u]*sz[u]+(n-sz[u])*(n-sz[u]));
}
void solve(){
    int n,m,c;
    cin>>n>>m>>c;
    vector<vector<int> > v (n+1,vector<int>());
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ans=(n-1)*(n-1)+1;
    vector<int> sz(n+1,1);
    for(int i=1;i<=n;i++){
        if(v[i].size()==1){
            dfs(i,v,-1,n,sz);
            break;
        }
    }
    cout<<ans<<"\n";
}
signed main() {
    int t;
    cin>>t;
    while(t--)
        solve();
}
