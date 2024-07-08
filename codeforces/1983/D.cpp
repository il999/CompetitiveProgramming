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
int inversions(vector<int> a,vector<int> ne){
    int n = a.size();
    map<int,int> ma;
    for(int i=0;i<n;i++) ma[ne[i]]=i;
    BIT fen(n);
    int inv=0;
    for(int i=n-1;i>=0;i--){
        inv+=fen.query(ma[a[i]]+1);
        fen.update(ma[a[i]]+1,1);
    }
    return (inv%2);

}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> ne1;
    vector<int> ne2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ne1.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        ne2.push_back(b[i]);
    }
    sort(ne1.begin(),ne1.end());
    sort(ne2.begin(),ne2.end());
    for(int i=0;i<n;i++) {
        if(ne1[i]!=ne2[i]){
            cout<<"NO\n";
            return;
        }
    }
    int t1 = inversions(a,ne1);
    int t2 = inversions(b,ne1);
    if (t1 == t2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


}

signed main(){
  //  ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}