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

int divide(int x, int y)
{
    return mul(x, inv(y));
}

bool abc(int a, int b, int c){
    if((max(b,c)-min(b,c))%2==1) return false;
    if(a==0&&max(b,c)-min(b,c)>0) return false;
    return true;
}
void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) {
        cout << "0 0 0\n";
        return;
    }
    cout<<abc(a,b,c)<<" "<<abc(b,a,c)<<" "<<abc(c,b,a)<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}