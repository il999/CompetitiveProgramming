#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

signed main() {
    int m, n; cin >> m >> n;
    vector<int> s(m+1), l(m+1);
    for (int i = 1; i <= m; ++i) cin >> s[i];
    for (int i = 1; i <= m; ++i) cin >> l[i];

    vector<int> end(m+1); end[1] = 1;
    for (int i = 0; i < n; ++i){
        vector<int> nend(m+1);
        for (int from = 1; from <= m; ++from){
            for (int to = 1; to <= m; ++to){
                int cnt = (((s[from] * l[to]) % mod + (s[to] * l[from])%mod)%mod + (s[from] * s[to])%mod)%mod;
                nend[to] += (end[from] * cnt) % mod; nend[to] %= mod;
            }
        }
        end = nend;
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i){
        ans += end[i]; ans %= mod;
    }
    cout << ans << "\n";

    return 0;
}
