#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <stack>
#include <cmath>
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
    ll l,r;
    cin>>l>>r;
 //  r = add(r,0);
  //  l = add (l , 0);
    ll cur=l;
    ll ans=0;
    ll t= floor(log2l(l))-1;
    while(cur<=r){
        t ++;
       // cout<<t<<"\n";
        ll curt=t;
        ll count=1;
        while(curt<((1ll<<(t+1))/t+1)&&curt*t<=cur){

            curt*=t;
            count++;
         //   cout<<curt<<" "<<t<<" "<<(1ll<<(t+1))/t<<"\n";
        }
        //cout<<count<<"\n";
        //curt*t<=1<<t+1
        while(curt<((1ll<<(t+1))/t+1)&&curt*t<=r&&floor(log2l(curt * t)) == t){
            curt =  (curt* t);
            ans=add(ans,mul(curt-max(cur,curt/t),count));
            count++;
           // cout<<curt<<"\n";
        }
        ll mi = min(r+1,(1ll<<(t+1)));
        ans=add(ans,mul(mi-max(cur,curt),count));
        cur=1ll<<(t+1);
     //   cout<<ans<<"ooh\n";


    }
    ll tpp=(1<<60);
 //   cout<<tpp<<"\n";
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