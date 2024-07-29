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
#include <chrono>
#include <numeric>
using namespace std;
const int MOD =1e9+7;
#define int long long
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
void solve() {
    int n;
    cin>>n;
    if(n==3){
        cout<<2<<"\n";
        cout<<"1 2 2"<<"\n";
        return;
    }
    vector<int> ans(2*n+1);

    for(int i=1;i<=n;i++){
        if((i%2)==1) ans[i]=1;
        else ans[i]=2;
        
    }
    for(int i=1;i<=n;i++){
        if((i&3)==0) ans[i+2]=4;
        else if((i&3)==1) ans[i+2]=3;
    }
    int col=0;
    for(int i=1;i<=n;i++){
        col=max(ans[i],col);
    }
    cout<<col<<"\n";
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();

}