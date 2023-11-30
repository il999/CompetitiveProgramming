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
    int n;
    cin>>n;
    ll a[n];
    ll ans=0;
    ll suff[n+1];
    suff[n]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    for(int i=n-1;i>=0;i--){
        suff[i]=suff[i+1]+a[i];
    }
    ll groups=1;

    for(int i=0;i<n;i++){
        if (i>0&&0<=suff[i]){
            groups++;
        }
        ans+=a[i]*groups;
    }
    cout<<ans<<"\n";





}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}