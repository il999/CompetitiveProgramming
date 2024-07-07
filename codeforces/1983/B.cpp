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
    int n,m;
    cin>>n>>m;
    string a[n];
    string b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int> totn(n);
    vector<int> totm(m);
    vector<int> totnb(n);
    vector<int> totmb(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            totn[i]+=a[i][j]-'0';
            totm[j]+=a[i][j]-'0';
            totnb[i]+=b[i][j]-'0';
            totmb[j]+=b[i][j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        if((totn[i]%3)!=(totnb[i]%3)){
            cout<<"NO\n";
            return;
        }
    }
    for(int i=0;i<m;i++){
        if((totm[i]%3)!=(totmb[i]%3)){
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
    while(t--)
        solve();
}