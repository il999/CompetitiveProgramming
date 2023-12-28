#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <cassert>
#include <stack>
#define int long long
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
void solve() {
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll low,high,mid;
    low=0;high=1e18;
    while(low<high){
        mid=(low+high)/2;
        int b[n];
        for(int i=0;i<n;i++) b[i]=a[i];
        int reserve=0;
        int rest=m;
        bool pos=1;
        for(int i=n-1;i>=0;i--){
            while(b[i]>0){
                if(reserve==0&&rest==0){
                    pos=false;
                    b[i]=0;
                    break;
                }
                if(reserve>0){
                    int tp=reserve;
                    reserve=max(reserve-b[i],0ll);
                    b[i]=max(0ll,b[i]-tp);
                }else{
                    reserve=max(0ll,mid-(i+1));
                    rest--;
                }
            }

        }
        if(!pos){
            low=mid+1;
        }else{
            high=mid;
        }
    }
    cout<<low<<"\n";

}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

        int t=1;
        while(t--) {
            solve();
        }
}