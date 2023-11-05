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

void solve() {

	int n; cin >> n;
	string s; cin >> s;
	vector<int> pref(2*n+1);
	if (s[0] == 'W') pref[0]++;
	for (int i = 1; i < 2*n + 1; ++i) pref[i] = pref[i-1] + (s[i] == 'W');
	
	int ans = 0;
	for (int i = 0; i < n; ++i){
		int rem = 0;
		if (i != 0) rem = pref[i-1];
		//cerr << pref[i + n - 1] << " " << pref[i] << " " << i << "\n";
		ans = max(ans, pref[i + n - 1] - rem);
	}
	
	cout << ans << "\n";

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