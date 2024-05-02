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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int firstzero = -1 ;
    int lastzero=0;
    for(int i =0;i<n;i++){
        if(a[i]==1) continue;
        if(firstzero==-1) firstzero=i;
        lastzero = i;
    }
    if(firstzero==-1) {
        cout<<"0\n";
        return;
    }
    cout<<lastzero-firstzero+2<<"\n";


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}