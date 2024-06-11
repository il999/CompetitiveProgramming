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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> reductions(k+1);
    for(int i=0;i<n;i++) cin>>a[i];
    int c=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]) c++;
        else {
            if(i-1-c>=0&&a[i]==a[i-1-c]) reductions[a[i-1]]+=2;
            else reductions[a[i-1]]++;
            c=1;
        }
    }
    reductions[a[n-1]]++;
    int in=0;
    int ma=0;
    for(int i=0;i<=k;i++){
        if(ma<reductions[i]){
            ma=reductions[i];
            in=i;
        }
    }
    cout<<in<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}