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
    string s;
    cin>>s;
    n=s.size();
    bool done=false;
    string s1="";
    s1+=s[0];
    for(int i=1;i<n;i++){

        if(!done&&s[i]==s[i-1]){
            if(s[i]=='a') s1+='z';
            else s1+='a';
            done=true;
        }
        s1+=s[i];
    }
    if(!done){
        if(s[n-1]=='a')s1+='z';
        else s1+='a';
    }
    cout<<s1<<"\n";

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();

}