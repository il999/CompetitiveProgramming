#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define ull unsigned long long
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define pll pair<long long, long long>
#define pdd pair<double, double>
#define s second
#define f first
#define pb push_back
#define oo 1000000000000000000ll
#define all(a) (a).begin(), a.end()
#define rall(a) (a).rbegin(), a.rend()
#define mp make_pair

void bernardo(int n, int x){
    cout << "Bernardo" << endl;
    for (int i = 0; i < n; ++i){
        int y, a; cin >> y >> a;
        int k = a + (x - a % x);
        if (a % x == 0) k = a;

        if (k < a + y) cout << k << endl;
        else cout << a << endl;
    }
}

void alessia(int n, int m, vector<int>& x){
    cout << "Alessia" << endl;
    sort(rall(x));
    set<pii> seg;
    seg.insert(mp(m, 1));
    for (int i = 0; i < n; ++i){
        auto cur = seg.lower_bound(mp(x[i], 0));
        cout << x[i] << " " << cur->s << endl;
        int k; cin >> k;
        seg.insert(mp(k - cur->s, cur->s));
        seg.insert(mp(cur->s + cur->f - k - 1, k+1));
        seg.erase(cur);
    }
}

void solve() {

    int n, m; cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    sort(all(x));
    for (int i = 0; i < n; ++i){
        if (m / x[i] < n - i) {
            bernardo(n, x[i]);
            return;
        }

    }
    alessia(n, m, x);

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tst; tst = 1;
    //cin >> tst;
    while (tst--){
        solve();
    }

    return 0;

}