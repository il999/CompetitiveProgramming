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
const int MOD =1e9+7;
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
void dfs(int u, int last, vector<vector<int> >& v,vector<int>& a){
    int mi=1e15;
    for(int to: v[u]){
        if(to==last) continue;
        dfs(to,u,v,a);
        mi=min(mi,a[to]);
    }
    if(u==0) a[u]+=mi;
    else if((mi!=((long long) 1e15))&&mi>a[u]) {
        a[u] += (mi - a[u]) / 2;
    }else if(mi<a[u]){
        a[u]=mi;
    }

}
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> p(n);
    vector<vector<int> > v (n,vector<int>());
    for(int i=1;i<n;i++){
        cin>>p[i];
        p[i]--;
        v[i].push_back(p[i]);
        v[p[i]].push_back(i);
    }

    dfs(0,-1,v,a);
    cout<<a[0]<<"\n";



}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();

}