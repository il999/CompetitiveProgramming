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
    int n,m,k;
    cin>>n>>m>>k;
    // only swim to the end anyways;
    string s;
    cin>>s;
    int lastlog=-1;
    int totalswim=0;
    for(int i=0;i<n;i++){
        if(s[i]=='L') lastlog=i;
        else if(s[i]=='C'&&(i-lastlog)>=m) {
            cout<<"NO\n";
            return;
        }else if(s[i]=='W'&&(i-lastlog)>=m){
            totalswim++;
        }
    }
    if(totalswim<=k){
        cout<<"YES\n";
        return;
    }else{
        cout<<"NO\n";
    }
}





signed main(){
  //  ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}