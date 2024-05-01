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
    int n,m;
    cin>>n>>m;
    int ans=0;
    map<array<int,2> ,bool> mp;

       // if(i%2==1) continue;
        for(int k=1;k*k<=m;k++){
            for(int q=1;q*q<=n;q++){
                if(GCD(k,q)==1){
                    int maxr = min((m/k),n/q);
                    ans+= (maxr)/(q+k);
                }

            }

        }

    cout<<ans<<"\n";


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}