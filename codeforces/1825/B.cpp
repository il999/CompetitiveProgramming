#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
using namespace std;
using ll=long long;
const int MOD=998244353;
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

int divide(int x, int y)
{
    return mul(x, inv(y));
}

void solve(){
    int n,m;
    cin>>n>>m;
    ll a[n*m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    sort(a,a+n*m);
    ll ans=0;
   
    ans=(a[n*m-2]-a[0])*(min(n,m)-1)+(a[n*m-1]-a[0])*((max(n,m)-1)*(min(n,m)));
    ans=max(ans,(a[n*m-1]-a[1])*(min(n,m)-1)+(a[n*m-1]-a[0])*((max(n,m)-1)*(min(n,m))));
    cout<<ans<<"\n";

}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
