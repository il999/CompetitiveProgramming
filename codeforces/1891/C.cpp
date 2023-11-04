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
 
int divide(int x, int y)
{
    return mul(x, inv(y));
}
void solve(){
    int n;
    cin>>n;
    ll a[n];
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll x=0;
    sort(a,a+n);
    ll attacks=0;
    ll total=0;
    for(int i=0;i<n;i++){
        total+=a[i];
        if(total>=((sum+1)/2)){

            if(total==(sum+1)/2){
                attacks+=(n-(i+1));
            }else{
                attacks+=(n-(i));
            }
            break;
        }
       // attacks+=a[i];

    }
    cout<<attacks+(sum+1)/2<<"\n";
        
   
 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}