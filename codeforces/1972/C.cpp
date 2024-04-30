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
    int n,k;
    cin>>n>>k;
    int c=0;
    int a[n];
    int ma=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        c+=a[i];
        ma=max(ma,a[i]);
    }
    int low=0;
    int high=ma+k+1;
    int works=0;
    while(low<high){
        int m = (low+high)/2;
        int needed=0;
        for(int i=0;i<n;i++){
            if(a[i]>m) continue;
            needed+=m-a[i];
        }
        if(needed<=k){
            low=m+1;
            works=m;
        }else{
            high=m;
        }
    }
    int  needed=0;
    for(int i=0;i<n;i++){
        if(a[i]>works) continue;
        needed+=works-a[i];
    }
    if(works==0){
        cout<<0<<"\n";
        return;
    }
    int perm=(n)*(works-1)+1+(k-needed);
    for(int i=0;i<n;i++){
        if(a[i]>works){
            perm++;
        }
    }
    cout<<perm<<"\n";


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

