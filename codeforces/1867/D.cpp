#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <stack>
#include <cmath>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
ll add(ll x, ll y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return x * 1ll * y % MOD;
}

ll binpow(ll x, ll y)
{
    ll z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

ll inv(ll x)
{
    return binpow(x, MOD - 2);
}

ll divide(ll x, ll y)
{
    return mul(x, inv(y));
}
vector<int> seen(200001);
vector<int> b(200001);
int n,k;
bool work=1;
void dfs(int u){
    //cout<<u<<"\n";
    seen[u] = 1;
    if (!work) return;
    if(seen[b[u]]==1){
        int len=1;
        for (int x = b[u] ; u!=x ; x= b[x]) len++;
        if(len!=k) {
            work=0;
            return;
        }
    }else if (seen[b[u]]==0) dfs(b[u]);
    seen[u]=-1;

}
void solve(){
    work=1;
   cin>>n>>k;
  // int b[n];
   for(int i = 0; i < n ;i ++){
       cin>>b[i+1];
      // v[i+1].clear();
       seen[i+1]=0;
       //cycle[i+1]=0;
   }
  // map <int,int> m;
   if(k==1) {
       for (int i = 1; i <= n; i++) {
            if(b[i]!=i){
                cout<<"NO\n";
                return;
            }
       }
       cout<<"YES\n";
       return;
   }

   for(int i=1;i<=n;i++){
       if(0 == seen[i]) {
            //cout<<i<<"\n";
           dfs(i);
       }
   }
   if(work) cout<<"YES\n";
   else cout<<"NO\n";


}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}