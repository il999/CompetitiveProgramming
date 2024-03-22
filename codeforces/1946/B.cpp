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
#define int long long
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
    int n,k;
    cin>>n>>k;
    int a[n];
    int maxsoffar=0;
    int mi=0;
    bool zero=false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0)zero=true;
        mi=max(a[i],mi);
    }
    int maxending=0;
    int total=0;
    for(int i=0;i<n;i++){
        maxending+=a[i];
        if(maxending>maxsoffar) maxsoffar=maxending;
        if(maxending<0) maxending=0;
        total=add(total,a[i]);
    }

    //maxending%=MOD;
    if(maxsoffar==0&&!zero){
        cout<<(add(mi*k,total))<<"\n";
    }else{
        int ans=total;
        for(int i=0;i<k;i++){
            ans=add(ans,maxsoffar);
            maxsoffar=mul(maxsoffar,2);
        }
        cout<<ans<<"\n";
    }
    //cout<<maxsoffar<<"\n";




}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

