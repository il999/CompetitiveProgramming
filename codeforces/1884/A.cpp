#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
ll add(ll x, ll y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return x * 1ll * y % MOD;
}

ll binpow(ll x, ll y)
{
    ll z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

ll inv(ll x)
{
    return binpow(x, MOD - 2);
}

ll divide(ll x, ll y)
{
    return mul(x, inv(y));
}

void solve(){
    int x;
    int k;
    cin>>x>>k;
    int tot;
    for(int i=0;i<20;i++) {
        tot=0;
        int orig=x;
        while (x > 0) {
            tot+= x%10;
            x/=10;
        }
        x=orig;
        if(tot%k>0) {
            x++;
           // cout<<"here\n";
        }else{
            cout<<x<<"\n";
            return;
        }
    }



}
int main()
{
  //  ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}