#include <bits/stdc++.h>

using namespace std;

void dfs1(int cur, int pr, vector<vector<int>>& ed, vector<int>& cnt){

    for (auto to : ed[cur]){
        if (pr == to) continue;
        dfs1(to, cur, ed, cnt);
        cnt[cur] += (cnt[to] == 0);
    }

}

void dfs2(int cur, int pr, vector<vector<int>>& ed, vector<bool>& can_win, vector<int>& cnt){
    for (auto to : ed[cur]){
        if (to == pr) continue;
        if (cnt[to] > 0 || cnt[cur] <= 1) can_win[to] = true;
        if ((cnt[to] == 0 && cnt[cur] == 1) || cnt[cur] == 0) cnt[to]++;
        dfs2(to, cur, ed, can_win, cnt);
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

    vector<int> cnt(n+1);
    dfs1(1, -1, ed, cnt);

    vector<bool> can_win(n+1);
    can_win[1] = cnt[1] > 0;
    dfs2(1, -1, ed, can_win, cnt);

    for (int i = 0; i < t; ++i){
        int st; cin >> st;
        if (can_win[st]) cout << "Ron\n";
        else cout << "Hermione\n";
    }

    return 0;
}
