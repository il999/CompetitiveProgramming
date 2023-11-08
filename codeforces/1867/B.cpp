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

int divide(int x, int y)
{
    return mul(x, inv(y));
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int diff=0;
    for(int i=0;i<n;i++){
        if(s[i]!=s[n-i-1]){
            diff++;
        }
    }
    diff/=2;
    string ans ="";
    for(int i=0;i<=n;i++) ans+='0';
    if(n%2==1) {
        for (int i = diff; i < n - diff + 1; i++){
            ans[i]='1';
        }
    }else{
        for (int i = diff ;i< n - diff + 1 ;i+=2){
            ans[i]='1';
        }
    }
    if( diff==0 ) ans[n]='1';

    cout<<ans<<"\n";



}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}