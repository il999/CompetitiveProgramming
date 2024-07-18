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
void solve() {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    map<int,array<int,2> > ma;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            ma[a[i][j]]={i,j};
        }
    }
    if(m!=1) {
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                swap(a[i][j], a[i][j-1]);
            }
        }
    }else if(n!=1){
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                swap(a[i][j],a[i-1][j]);
            }
        }
    }else{
        cout<<"-1\n";
        return;
    }
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            cout<<a[i][j]<<" ";

        }
        cout<<"\n";
    }



}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();

}