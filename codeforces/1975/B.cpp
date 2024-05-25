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
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int end=-1;
    for(int i=1;i<n;i++){
        if((a[i]%(a[0]))!=0){
            end=i;
            break;
        }
    }
    if(end==-1){
        cout<<"YES\n";
        return;
    }
    for(int i=end+1;i<n;i++){
        if(((a[i]%a[0])!=0)&&((a[i]%a[end])!=0)){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}