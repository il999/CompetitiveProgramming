#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

vector<vector<int>> mult(vector<vector<int>>& m1, vector<vector<int>>& m2){
    int m = m1.size();
    vector<vector<int>> res(m, vector<int>(m));
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < m; ++j){
            for (int k = 0; k < m; ++k){
                res[i][j] += (m1[i][k] * m2[k][j]) % mod;
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

vector<vector<int>> matpow(vector<vector<int>>& mat, int p){
    if (p == 1) return mat;
    else if (p % 2 == 0){
        vector<vector<int>> k = matpow(mat, p/2);
        return mult(k, k);
    } else {
        vector<vector<int>> k = matpow(mat, p-1);
        return mult(k, mat);
    }
}

signed main() {
    int m, n; cin >> m >> n;
    vector<int> s(m), l(m);
    for (int i = 0; i < m; ++i) cin >> s[i];
    for (int i = 0; i < m; ++i) cin >> l[i];

    vector<vector<int>> mat1(m, vector<int>(m));
    for (int i = 0; i < m; ++i) mat1[0][i] = 1;

    vector<vector<int>> mat2(m, vector<int>(m));
    for (int from = 0; from < m; ++from){
        for (int to = 0; to < m; ++to){
            mat2[from][to] = (((s[from] * l[to]) % mod + (s[to] * l[from])%mod)%mod + (s[from] * s[to])%mod)%mod;
        }
    }

    vector<vector<int>> pow = matpow(mat2, n);
    vector<vector<int>> mat = mult(mat1, pow);

    int ans = mat[0][0];
    cout << ans << "\n";

    return 0;
}
