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
int GCD(int a, int b){
    if(a<b) swap(a,b);
    if(a%b==0) return b;
    return GCD(b,a%b);
}
void solve() {
    int p[3];
    cin>>p[0]>>p[1]>>p[2];
    sort(p,p+3);
    int sum = p[0]+p[1]+p[2];
    if(sum%2==1) {
        cout << "-1\n";
        return;
    }
    int ans= (p[0])+min((p[2]-p[0]+p[1])/2,p[1]);
    cout<<ans<<"\n";



}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}