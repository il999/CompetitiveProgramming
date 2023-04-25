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
   ll a[n];
   map<ll,ll> m;
   for(int i=0;i<n;i++){
    cin>>a[i];
    if(m.find(a[i])==m.end())m[a[i]]=1;
    else m[a[i]]++;
   }

   ll ans=0;
   for(auto it: m){
    if(it.second>=3)ans+=((it.second)*(it.second-1)*(it.second-2));
    for(int j=2;it.first*j*j<1000001;j++){
        if(m.find(it.first*j*j)!=m.end()&&m.find(it.first*j)!=m.end()){
            ans+=it.second*m[it.first*j*j]*m[it.first*j];
        }
    }
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
