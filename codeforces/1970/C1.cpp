#include <bits/stdc++.h>

using namespace std;

int dfs(int cur, int pr, vector<vector<int>>& ed){
    for (auto to : ed[cur]){
        if (to == pr) continue;
        return dfs(to, cur, ed);
    }
    return cur;
}

void calc_dist(int cur, int pr, vector<vector<int>>& ed, vector<int>& dist){
    dist[cur] = dist[pr] + 1;
    for (auto to : ed[cur]){
        if (to == pr) continue;
        calc_dist(to, cur, ed, dist);
    }
}

int main() {
    int n, t; cin >> n >> t;
    vector<vector<int>> ed(n+1);
    for (int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }

    int l = dfs(1, -1, ed);
    int r = dfs(l, -1, ed);
    vector<int> ldist(n+1, -1), rdist(n+1, -1);
    calc_dist(l, l, ed, ldist);
    calc_dist(r, r, ed, rdist);

    for (int i = 0; i < t; ++i){
        int st; cin >> st;
        int ld = ldist[st];
        int rd = rdist[st];
        if (ld % 2 == 1 || rd % 2 == 1) cout << "Ron\n";
        else cout << "Hermione\n";
    }

    return 0;
}
