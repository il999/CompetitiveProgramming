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
void solve() {
    int n;
    cin>>n;
    int ma=0;
    vector<int> a(n);
    for(int i=0;i<n-1;i++) cin>>a[i];
    vector<int> ans(n);
   // cout<<(1<<3)<<"\n";
    for(int i=0;i<n-1;i++){
        for(int j=0;j<31;j++){
            if((a[i]&((1ll)<<j))){
                ans[i]+=(1<<j);
                if(!(a[i+1]&((1ll)<<j))){
                    ans[i+1]+=(1<<j);
                }
            }
        }
    }
    for(int i=0;i<n-1;i++){
        if((ans[i]&ans[i+1])!=a[i]){
            cout<<"-1\n";
            return;
        }
    }
    for(int x: ans){
        cout<<x<<" ";
    }
    cout<<"\n";

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();

}