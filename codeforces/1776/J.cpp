#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iomanip>
#include <map>
#include <cassert>
#include <numeric>

using namespace std;

#define MOD 1000000007

int N, M, K, dp[111][111][2], c[111];
vector<int> adj[111];

int main()
{
    if (fopen("data.in", "r"))
        freopen("data.in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int p = 0; p < 2; p++) {
                dp[i][j][p] = (1 << 20);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        cin >> c[i];
        dp[i][i][0] = 0;
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        a--;
        b--;
        dp[a][b][c[a] != c[b]] = 1;
        dp[b][a][c[a] != c[b]] = 1;
    }
    
    for (int d = 0; d < 2; d++) {
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (int p = 0; p < 2; p++) {
                        for (int p2 = 0; p2 < 2; p2++) {
                            dp[i][j][p^p2] = min(dp[i][j][p^p2], dp[i][k][p] + dp[k][j][p2]);
                        }
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (dp[i][j][0] > dp[i][j][1])
                swap(dp[i][j][0], dp[i][j][1]);
            if (dp[i][j][0] + K <= dp[i][j][1])
                ans = max(ans, dp[i][j][0] + K);
            else
                ans = max(ans, dp[i][j][1] + (K + dp[i][j][0] - dp[i][j][1]) / 2);
        }
    }
    
    cout << ans << endl;
}
