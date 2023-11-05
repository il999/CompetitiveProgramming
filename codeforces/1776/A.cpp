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
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	int k = 0;
	for (int i = 1; i < n; ++i){
		k += (a[i] - a[i-1]) / 120;
 	}
 	
 	k += a[0] / 120; 
 	k += (1440 - a.back()) / 120;
 	
 	if (k > 1) cout << "YES\n";
 	else cout << "NO\n";

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tst; tst = 1;
    cin >> tst;
    while (tst--){
        solve();
    }

    return 0;

}