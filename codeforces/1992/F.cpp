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
vector<int> primes;
void solve() {
    //100 friends, 10^5 apples
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int segments = 1;
    vector<int> sofar;

    for (int i = 0; i < n; i++) {
        if (x%a[i]!=0) continue;
        int top = sofar.size();
        for (int j = 0; j < top; j++) {
            if (__gcd(a[i] * sofar[j], x) == a[i] * sofar[j]) {
                sofar.push_back(a[i] * sofar[j]);
            }
        }
        sofar.push_back(a[i]);
        sort(sofar.begin(), sofar.end());
        sofar.erase(unique(sofar.begin(), sofar.end()), sofar.end());

        if (sofar.back() == x) {
            segments++;
            sofar.clear();
            sofar.push_back(a[i]);
        }

    }
    cout << segments << "\n";
}





signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();

}