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

    int n, x;
    cin >> n >> x;
    int a[n];
    int ma = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int c = 0;

    }
    int tp=x;
    while(tp>0){
        tp/=2;
        ma++;
    }
    int ans=0;

    for (int i = ma; i >= 0; i--) {
        int cur = 0;
        int ct=0;
        if((x&(1<<i))==0) continue;
        for (int j = 0; j < n; j++) {
            cur ^= a[j];
            bool worked=1;
            for(int k=i+1;k<30;k++){
                if(((cur&(1<<k))>0)&&((x&(1<<k))==0)){
                    worked=0;
                    break;
                }
            }
            if((cur&(1<<i))>0) worked=0;
            if(worked){
                cur=0;
                ct++;
            }
        }

        if(cur==0)
            ans=max(ct,ans);
    }
    int cur=0;
    int ct=0;
    for (int j = 0; j < n; j++) {
        cur ^= a[j];
        bool worked=1;
        for(int k=0;k<30;k++){
            if(((cur&(1<<k))>0)&&((x&(1<<k))==0)){
                worked=0;
                break;
            }
        }
        if(worked){
            cur=0;
            ct++;
        }
    }
    if(cur==0)ans=max(ct,ans);
    if(ans==0) ans=-1;
    cout<<ans<<"\n";


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

