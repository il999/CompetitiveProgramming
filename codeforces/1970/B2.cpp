#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i;

    vector<int> to(n);
    vector<pair<int, int>> idx(n);
    idx[0] = {1, 1}; to[0] = 0;
    sort(a.rbegin(), a.rend());
    int prev = 0;
    int sign = 1;
    for (int i = 0; i < n-1; ++i){
        if (a[i].first == 0) idx[a[i].second] = {i+2, i+2}, to[a[i].second] = a[i].second;
        else {
            idx[a[i].second] = {i+2, idx[prev].second + sign * (a[i].first - 1)};
            to[a[i].second] = prev;
            prev = a[i].second;
            sign *= -1;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i){
        cout << idx[i].first << " " << idx[i].second << "\n";
    }
    for (int i = 0; i < n; ++i) cout << to[i] + 1 << " ";
    cout << '\n';


    return 0;
}
