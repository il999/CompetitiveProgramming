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

int dp[305][305];

int f(int l, int r, int h, vector<int>& x){
	if (dp[l][r] != -1) return dp[l][r];
	
	if (l == r) return dp[l][r] = h;
	
	dp[l][r] = oo;
	for (int k = l; k < r; ++k){
		dp[l][r] = min(dp[l][r], f(l, k, h, x) + f(k+1, r, h, x) - (h - (x[r] - x[l] + 1) / 2 + 1));
		dp[l][r] = min(dp[l][r], f(l, k, h, x) + f(k+1, r, h, x));
	}
	
	return dp[l][r];
}

void solve() {

	int n, h; cin >> n >> h;
	vector<int> x(n);
	for (int i = 0; i < n; ++i) cin >> x[i];
	
	memset(dp, -1, sizeof(dp));
	cout << f(0, n-1, h, x) << "\n";
	

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