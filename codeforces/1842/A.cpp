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
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[m];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    ll t1=0;
    ll t2=0;
    for(int i=0;i<n;i++)t1+=a[i];
    for(int i=0;i<m;i++)t2+=b[i];
    if(t1>t2){
        cout<<"Tsondu\n";
    }else if(t2>t1){
        cout<<"Tenzing\n";
    }else{
        cout<<"Draw\n";
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