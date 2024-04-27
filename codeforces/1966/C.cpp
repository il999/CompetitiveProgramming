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
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int onediff=1;
    int different=n;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            different--;
        }
    }
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]) {
            continue;
        }
        if(a[i]-a[i-1]!=1) break;
        onediff++;
    }
    if(a[0]!=1) onediff=0;

    if(onediff==different){
        if((different)%2==1) cout<<"Alice\n";
        else cout<<"Bob\n";
    }else{
        if(onediff%2==1) cout<<"Bob\n";
        else cout<<"Alice\n";
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

