#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<string>> grid(n, vector<string>(m));
    map<string, pair<int, int>> pos;
    map<pair<int, int>, bool> red_goal, blue_goal;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == "..") continue;
            else if (grid[i][j] == "RG") red_goal[{i, j}] = true;
            else if (grid[i][j] == "BG") blue_goal[{i, j}] = true;
            else pos[grid[i][j]] = {i, j};
        }
    }

    int t; cin >> t;
    bool has_the_ball = false;
    int blue = 0, red = 0;
    for (int i = 0; i < t; ++i){
        string cur; char c;
        cin >> cur >> c;
        if (c == 'U') pos[cur].first--;
        else if (c == 'D') pos[cur].first++;
        else if (c == 'L') pos[cur].second--;
        else if (c == 'R') pos[cur].second++;
        else if (c == 'C'){
            string ball; cin >> ball;
            has_the_ball = true;
        } else{
            if (red_goal[pos[cur]]){
                cout << i << " BLUE GOAL\n";
                blue++;
            } else if (blue_goal[pos[cur]]){
                cout << i << " RED GOAL\n";
                red++;
            }
        }
    }

    cout << "FINAL SCORE: " << red << " " << blue << "\n";



    return 0;
}
