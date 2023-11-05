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

vector<int> remove(vector<int>& v, int k){
    vector<int> nv;
    for (auto x : v){
        if (x != k) nv.pb(x);
    }
    return nv;
}

int get_minimum(vector<int>& v, vector<int>& x, vector<int>& y){
    double min = (double)(oo);
    int idx = -1;
    for (int i = 0; i < v.size(); ++i){
        int prev = i-1;
        if (i == 0) prev = v.size() - 1;
        int nxt = i+1;
        if (i == v.size() - 1) nxt = 0;
        int cur = v[i];
        prev = v[prev], nxt = v[nxt];

        double s1 = sqrt((x[cur] - x[nxt]) * (x[cur] - x[nxt]) + (y[cur] - y[nxt]) * (y[cur] - y[nxt]));
        double s2 = sqrt((x[cur] - x[prev]) * (x[cur] - x[prev]) + (y[cur] - y[prev]) * (y[cur] - y[prev]));
        double s3 = sqrt((x[prev] - x[nxt]) * (x[prev] - x[nxt]) + (y[prev] - y[nxt]) * (y[prev] - y[nxt]));
        double p = (s1 + s2 + s3) / 2;
        double curl = sqrt(p * (p - s1) * (p - s2) * (p - s3));
        if (curl < min) min = curl, idx = cur;
    }

    return idx;

}

void solve() {

    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }

    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = i;
    if (n % 2) {
        cout << "Beatrice" << endl;
        int k; cin >> k;
        v = remove(v, k-1);
    } else{
        cout << "Alberto" << endl;
    }

    for (int i = 0; i < (n-2) / 2; ++i){
        int xx = get_minimum(v, x, y);
        cout << xx+1 << endl;
        v = remove(v, xx);
        int k; cin >> k;
        v = remove(v, k-1);
    }

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