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
#include <chrono>
using namespace std;
const int MOD =998244353;
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

void solve() {
    vector<int> three(3);
    cin>>three[0]>>three[1]>>three[2];
    for(int i=0;i<5;i++){
        sort(three.begin(),three.end());
        three[0]++;
    }
    cout<<three[0]*three[1]*three[2]<<"\n";

}

signed main(){
  //  ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}