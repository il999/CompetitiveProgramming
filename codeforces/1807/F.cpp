#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ln '\n'

map<string, pair<int, int>> mp;

void solve(){
    int n, m, i1, j1, i2, j2;
    string d;

    mp["DR"] = {1,1};
    mp["DL"] = {1,-1};
    mp["UR"] = {-1,1};
    mp["UL"] = {-1,-1};

    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;
    if(i1==i2&&j1==j2){
        cout<<"0\n";
        return;
    }
    int x = mp[d].first, y = mp[d].second;
    int curx = i1, cury = j1;
    int tx, ty;

    int tmp1, tmp2;

    bool ok = false;
    map<array<int, 4>, int> seen;
    int cnt = 0;

    int glit = 0;
    while (!ok){
        if (++seen[{curx, cury, x, y}] == 3) break;

        // cout << curx << ' ' << cury << ln;
        // cout << x << ' ' << y << ln;
        // check travel
        // check if target is on path
        tmp1 = i2 - curx;
        tmp2 = j2 - cury;

        // same direction
        bool a1 = (tmp1 > 0) == (x > 0);
        bool a2 = (tmp2 > 0) == (y > 0);

        if (a1 && (a2 && abs(tmp1) == abs(tmp2))) {
            ok = true;
            break;
        }

        // calculate bounce
        if (x == 1 && y == 1){
            tx = n-curx;
            ty = m-cury;
        } else if (x == 1 && y == -1){
            tx = n-curx;
            ty = cury-1;
        } else if (x == -1 && y == 1){
            tx = curx-1;
            ty = m-cury;
        } else {
            tx = curx-1;
            ty = cury-1;
        }



        if (tx == ty){
            // hit corner

            if (x == 1) curx += tx;
            else curx -= tx;

            if (y == 1) cury += ty;
            else cury -= ty;

            x = -x;
            y = -y;

        } else if (tx > ty){
            // hit y axis


            if (x == 1) curx += ty;
            else curx -= ty;

            if (y == 1) cury += ty;
            else cury -= ty;

            y = -y;

        } else {


            if (x == 1) curx += tx;
            else curx -= tx;

            if (y == 1) cury += tx;
            else cury -= tx;

            x = -x;
        }


        cnt++;


    }

    if (ok) cout << cnt << ln;
    else cout << -1 << ln;






}




int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);


    int T; cin >> T;
    while (T--){
        solve();
    }

    // solve();





    return 0;
}







