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

int divide(int x, int y)
{
    return mul(x, inv(y));
}
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int ones=0;
    int zeros=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') ones++;
        else zeros++;
    }
    int currentz=0;
    int ans=n;
    int currento=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') currento++;
        else currentz++;
        if(currento<=zeros&&currentz<=ones){
            ans=n-i-1;
        }
    }
    cout<<ans<<"\n";

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

        int t;
        cin>>t;
        while(t--) {
            solve();
        }
}