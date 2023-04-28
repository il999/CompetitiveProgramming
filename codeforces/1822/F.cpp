#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
using namespace std;
using ll=long long;
const int MOD=998244353;
int add(int x, int y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;   
}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int inv(int x)
{
    return binpow(x, MOD - 2);    
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}
vector<vector<int> > v(200002,vector<int>());
vector<bool> seen(200002);
ll ma=0;
int in=0;
vector<ll> dis(200002);
void dfs(int u){
    for(int i=0;i<v[u].size();i++){
        if(!seen[v[u][i]]){
            seen[v[u][i]]=1;
            dis[v[u][i]]=dis[u]+1;
            if(ma<dis[v[u][i]]){
                ma=dis[v[u][i]];
                in=v[u][i];
            }
            dfs(v[u][i]);
        }
    }
}
void solve(){
   
   // int n;
   ll n,c,k;
   cin>>n>>k>>c;
   ma=0;
   for(int i=0;i<n;i++){
    v[i].clear();
    seen[i]=0;
    dis[0]=0;
   }
   int a,b;
   for(int i=0;i<n-1;i++){
    cin>>a>>b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
   }
   dis[0]=0;
   seen[0]=1;
   dfs(0);
   
   ll original[n];
   for(int i=0;i<n;i++){
    //cout<<dis[i]<<" ";a
    original[i]=dis[i];
    dis[i]=0;
    seen[i]=0;
   }
   //cout<<"\n";
   ma=0;
   seen[in]=1;
   dfs(in);
    ll dis2[n];
    for(int i=0;i<n;i++){
        dis2[i]=dis[i];
        dis[i]=0;
        seen[i]=0;
    }
    ma=0;
    seen[in]=1;
    //in=0;
    dfs(in);
    ll ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,-c*original[i]+max(dis[i],dis2[i])*k);
    }
    cout<<ans<<"\n";

   


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
