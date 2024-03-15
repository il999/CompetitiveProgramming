#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <stack>
using namespace std;
using ll=long long;
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

void solve(){
    int n;
    cin>>n;
    int a[n];
    int pos=-1;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i-1]>a[i]){
            pos=i-1;
        }
    }
    vector<int> nearray;
    int last=0;
    for(int i=0;i<n;i++){
        if(i<=pos){
            if(a[i]>=10) nearray.push_back(a[i]/10);
            nearray.push_back(a[i]%10);
        }else nearray.push_back(a[i]);
    }
    for(int i=1;i<nearray.size();i++){
        if(nearray[i]<nearray[i-1]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";



}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

