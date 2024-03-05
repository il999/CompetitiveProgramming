#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
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

int divide(int x, int y) {
    return mul(x, inv(y));
}
void solve(){
    ll n;
    ll c;
    cin>>n>>c;
    ll s[n];
    for(int i=0;i<n;i++) cin>>s[i];
    vector<ll> parity(2);
    vector<vector<ll> > parity2(n+1,vector<ll>(2));
    for(int i=1;i<=n;i++){
        parity2[i]=parity2[i-1];
        parity2[i][s[i-1]%2]++;
    }
    ll tot=0;
    for(int i=n-1;i>=0;i--){
        tot+=(s[i])/2+1+c-s[i]-parity[s[i]%2];
        parity[s[i]%2]++;
    }
   // cout<<tot<<"\n";
    cout<<(1ll*((c+2)*(c+1))/2)-tot<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
