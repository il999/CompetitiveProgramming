#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    cout << "YES\n";
    for (int i=1; i<=n; i++) cout << i << " " << i << '\n';
    for (int i=1; i<=n; i++) {
        if (i + a[i-1]/2 <= n) cout << i + a[i-1]/2 << " ";
        else cout << i - a[i-1]/2 << " ";
    }
    return 0;
}
