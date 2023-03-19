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
    ll c[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    ll pre[n+1];
    pre[0]=0;
    pre[1]=1;
   sort(c,c+n);
   if(c[0]!=1){
    cout<<"NO\n";
    return;
   }
    vector<int> dp(200001,0);
   dp[1]=1;
   for(int i=1;i<n;i++){
    if(dp[c[i]]==0){
        cout<<"NO\n";
        return;
    }else{
        for(int j=200001;j>=c[i];j--){
            dp[j]+=dp[j-c[i]];
        }
    }
   }
   cout<<"YES\n";


    

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
