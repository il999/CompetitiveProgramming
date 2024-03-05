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
    int r;
    cin>>r;
    string s;
    cin>>s;
    int n=s.size();
    string two="";
    for (int i=n-1;i>=0;i--){
        two+=s[i];
    }
   // cout<<two<<" gek";
    bool winnerone=1;
    for(int i=0;i<n;i++){
        if(s[i]-'a'>two[i]-'a'){
            winnerone=0;
            break;
        }else if(s[i]-'a'<two[i]-'a'){
            break;
        }
    }
    if(winnerone){
        cout<<s<<"\n";
    }else{
        cout<<two<<s<<"\n";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
