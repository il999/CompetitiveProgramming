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
struct BIT {
    int n, rtn; // rtn might need to be LLed
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1,0) {}
    void update(int x, int d) { for (int i = x; i <= n; i += i & -i) bit[i] += d; }
    int query(int x) {
        rtn = 0;
        for (int i = x; i; i -= i & -i) rtn += bit[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) - query(x - 1); }
};
void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> kstay(n+3);
    BIT fen(n+3);
    for(int i=0;i<n;i++){
      //  cout<<"HELLO\n";
        int low =1;
        int high=n+1;
        if(i==3){
           // cout<<fen.query(3)<<" "<<"what the fuck\n";
        }
        while(low<high){
            int mid = (low+high)/2;
            if((fen.query(mid))/mid+1>a[i]) low = mid+1;
            else high=mid;
        }
        if(high==n+1){
            kstay[i]=n+4;
            continue;
        }
        fen.update(high,1);
        kstay[i]=high;
    }
    int b,x;
    while(q--){
        cin>>b>>x;
        b--;
        if(kstay[b]>x) cout<<"NO\n";
        else cout<<"YES\n";
        //cout<<kstay[b]<<" "<<b<<" "<<x<<"\n";
    }



}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();

}