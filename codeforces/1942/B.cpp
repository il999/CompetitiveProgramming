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
void solve() {
    int n;
    cin>>n;
    vector<int> a (n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> ans(n);
    vector<bool> used(n+40);
    int mex=0;
    if(a[0]==1) {
        ans[0]=0;
        mex=1;
    }
    else{
        ans[0]=-a[0];
    }
    used[ans[0]]=1;
    for(int i=1;i<n;i++){
        while(used[mex]){
            mex++;
        }
      //  cout<<mex-a[i]<<"\n";
        if(mex-a[i]<0||used[mex-a[i]]){
            //mex needs to change;
            used[mex]=1;
            mex++;
            ans[i]=mex-1;
        }else {
            ans[i] = (mex - a[i]);
        }
        used[ans[i]]=1;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";

    }
    cout<<"\n";
    //decide wether first mex is 0 or one depens on the negative



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

