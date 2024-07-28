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
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++){
        if((a[i]%2)!=(a[i+1]%2)){
            cout<<"-1\n";
            return;
        }
    }
    vector<int> ans;
    for(int j=0;j<40;j++){
        ans.push_back(a[n-1]/2);
        for(int i=0;i<n;i++){
            a[i]=abs(a[i]-(a[n-1])/2);
        }
        sort(a.begin(),a.end());
        if(a[n-1]==1){
            ans.push_back(1);
            break;
        }else if(a[n-1]==0) break;
    }
    cout<<ans.size()<<"\n";
    for(int x: ans){
        cout<<x<<" ";
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