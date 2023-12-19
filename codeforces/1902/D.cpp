#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <cassert>
#include <stack>
using namespace std;
using ll=long long;
const int MOD=998244353;
int add(int x, int y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}
void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    map<array<int, 2>, vector<int> > m;
    map<array<int, 2>, vector<int> > m2;
    int x = 0, y = 0;
    vector<array<int, 2> > cur, cur2;
    cur.push_back({0, 0});

    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') y++;
        else if (s[i] == 'D')y--;
        else if (s[i] == 'R') x++;
        else x--;
        
            m[{x,y}].push_back(i);
        
        cur.push_back({x, y});
    }
    cur2.push_back({0, 0});
    x=y=0;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'U') y++;
        else if (s[i] == 'D')y--;
        else if (s[i] == 'R') x++;
        else x--;
        
            m2[{x,y}].push_back(i);
        
        cur2.push_back({x, y});
    }
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        c--;
        d--;
        if(a==b&&a==0){
            cout<<"YES\n";
            continue;
        }
        bool done = false;
        if (m.find({a, b}) != m.end() && (m[{a, b}][0] < c || m[{a, b}].back() > d)) {
            done = true;
        }
        if (!done) {

            a = a - cur[c][0] + cur2[n-d-1][0];
            b = b - cur[c][1] + cur2[n-d-1][1];
          //  cout<<cur[c][0]<<" "<<cur2[n-d-1][0]<<" "<<cur[c][1]<<" "<<cur2[n-d-1][1]<<"\n";
            if(a==b&&a==0){
              //  continue;
            }
            if (m2.find({a, b}) != m2.end()) {
                int low, mid, high;
                low = 0;
                high = m2[{a, b}].size() - 1;
                while (low < high) {
                    mid = (low + high) / 2;
                    if (m2[{a, b}][mid] > d) {
                        low = mid + 1;
                    } else {
                        high = mid;
                    }
                }
                if (m2[{a,b}][high] >= c && m2[{a,b}][high] <= d) {
                    done = 1;
                  //  cout<<a<<" "<<b<<" ";
                }
            }
        }
        if (done) cout << "YES\n";
        else cout << "NO\n";
    }

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

        int t=1;
        while(t--) {
            solve();
        }
}