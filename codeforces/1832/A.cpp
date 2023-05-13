#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
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

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> alpha(26);
    for(int i=0;i<n;i++){
        if(s[i]==s[n-i-1]&&i!=n-i-1){
            alpha[s[i]-'a']++;
        }
    }
    sort(alpha.rbegin(),alpha.rend());
    if(alpha[0]>0&&alpha[1]>0){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
