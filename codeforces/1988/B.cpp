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
#include <numeric>
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int zeros=0;
    int ones=0;
    int c=1;
    if(s[0]=='0') zeros++;
    else ones++;
    for(int i=1;i<n;i++){
        if(s[i]=='1') ones++;
        if(s[i]==s[i-1])c++;
        else{
            c=1;
            if(s[i]=='0') zeros++;

        }
    }
    if(ones>zeros){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
     cin>>t;
    while(t--)
        solve();

}