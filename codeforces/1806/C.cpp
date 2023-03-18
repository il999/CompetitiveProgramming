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
   
    int n;
    cin>>n;
    n*=2;
   
    //big can go with 2 small
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
   
    if(n==2){
        cout<<abs(a[1]-a[0])<<"\n";
        return;
    }
   
    sort(a,a+n);
   // ar.push_back(n/2);
    ll ans=0;
    ll tp=0;
    for(int i=0;i<n;i++){
        ans+=abs(-1-a[i]);
        tp+=abs(a[i]);
    }
    ll realans=1e18;
    if(n%4==0){

    
     
        //cout<<ans<<"\n";
        for(int i=0;i<n;i++){
            realans=min(realans,ans-(abs(-1-a[i]))+abs(n/2-a[i]));
        }
    }
    ll tp2=1e18;
     if(n==4){
        tp2=0;
        for(int i=0;i<n;i++){
            tp2+=abs(a[i]-2);
        }
        tp=min(tp2,tp);
    }

    cout<<min(tp,realans)<<"\n";
  
   // cout<<other<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
