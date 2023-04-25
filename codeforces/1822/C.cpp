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
   
   // int n;
   ll n;
   cin>>n;
   ll ans=0;
   if(n==4)cout<<26<<"\n";
   else{
    cout<<n*n-16+(n-4)*2+26<<"\n";
   }
   


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
