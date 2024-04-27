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
const int MOD=1e9+7;
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

int divide(int x, int y) {
    return mul(x, inv(y));
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<bool> brow(n);
    vector<bool> wrow(n);
    vector<bool> bcol(m);
    vector<bool> wcol(m);
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
        for(int j=0;j<m;j++)
            if(grid[i][j]=='B') brow[i] = true,bcol[j]=true;
            else wrow[i] = true,wcol[j]=true;
    }
    if(bcol[0]&&brow[0]&&bcol[m-1]&&brow[n-1]){
        cout<<"YES\n";
    }else if(wcol[0]&&wrow[0]&&wcol[m-1]&&wrow[n-1]) {
        cout << "YES\n";
    }else cout<<"NO\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

