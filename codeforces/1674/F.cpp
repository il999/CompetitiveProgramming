#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <stack>
using namespace std;
const int MOD=998244353;
#define int long long

struct BIT {
    int n,m,rtn;
    vector<vector<int>> bit;
    BIT(int n, int m) : n(n), m(m), bit(n+1,vector<int> (m+1,0)) {}
    void update(int x, int y, int d) {
        for (int i=x;i<=n;i+=i&-i)
            for (int j=y;j<=m;j+=j&-j)
                bit[i][j]+=d;
    }
    int query(int x, int y) {
        rtn=0;
        for (int i=x;i;i-=i&-i)
            for (int j=y;j;j-=j&-j)
                rtn+=bit[i][j];
        return rtn;
    }
    int query(int a, int b, int c, int d) {
        return query(c,d) - query(a-1,d) - query(c,b-1) + query(a-1,b-1);
    }
};
void solve() {
    int n, m ,q;
    cin>>n>>m>>q;
    char grid[n+1][m+1];
    BIT fen(n,m);
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if(grid[i][j]=='*') fen.update(i,j,1);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(grid[x][y]=='*') {
            grid[x][y]='.';
            fen.update(x,y,-1);
        }else{
            grid[x][y]='*';
            fen.update(x,y,1);
        }

        int stars =fen.query(n,m);
        int fullrows=stars/n;
        int extraneeded = stars%n;
        int alreadyinplace = fen.query(n,fullrows) + fen.query(1,fullrows+1,extraneeded,fullrows+1);
        cout<<stars-alreadyinplace<<"\n";

    }





}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--) solve();
}