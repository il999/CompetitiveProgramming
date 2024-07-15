#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <stack>
#include <chrono>
#include <numeric>
using namespace std;
const int MOD =998244353;
#define int long long
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

int divide(int x, int y) {
    return mul(x, inv(y));
}
void dfs(int u, vector<int>& a,vector<vector<int> >& v, vector<vector<int> >& dp,int last){
    for(int i=1;i<23;i++) dp[u][i] = i*a[u];
    for(int to :v[u]){
        if(to == last) continue;
        dfs(to,a,v,dp,u);
        for(int i=1;i<23;i++){
            int mi=1e18+24;
            for(int j=1;j<23;j++){
                if(i!=j)
                    mi=min(dp[to][j],mi);
            }
            dp[u][i]+=mi;
        }
    }

}
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int total=0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        total+=a[i];
    }
    int x,y;
    vector<vector<int> > v (n,vector<int>());
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        x--;y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<vector<int> > dp (n+1,vector<int>(23,1e18));
    dfs(0,a,v,dp,-1);
    sort(dp[0].begin(),dp[0].end());
    cout<<dp[0][0]<<"\n";


}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
     cin>>t;
    while(t--)
        solve();

}