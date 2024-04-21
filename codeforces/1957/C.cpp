#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <stack>
using namespace std;
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
int choose2(int n){
    return divide(mul(n,(n-1)),2);
}
void solve() {
    int n,k;
    cin>>n>>k;
    map<int,int> m;
    int alreadyused=0;
    int a;
    for(int i=0;i<k*2;i++){
        cin>>a;
        if(m.find(a)==m.end()){
            alreadyused++;
            m[a]=1;
        }
    }
    vector<array<int,2> > dp(n-alreadyused+1,{0,0});
    //first thing means how many pieces left;
    dp[0][0]=1;
    int fact[n+1];
    fact[0]=1;
    for(int i=1;i<n;i++){
        fact[i]=mul(i,fact[i-1]);
    }
    // cout<<alreadyused<<"\n";
    int ansnow=0;
    for(int i=1;i<(n-alreadyused)+1;i++){
        if(i%2==0) dp[i][0] =mul(2,mul(dp[i-2][0],choose2(n-alreadyused-i+2)));

        if(i%2==1) ansnow = add(divide(dp[i-1][0],(fact[i/2])),ansnow);
        //  cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    }
    if((n-alreadyused)%2==0){
        ansnow=add(ansnow,divide(dp[n-alreadyused][0],fact[(n-alreadyused)/2]));
    }
    cout<<ansnow<<"\n";
    //cout<<add(ans,ans2)<<"\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

