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
    int n;
    cin>>n;
    string s;
    cin>>s;
    char initial=s[0];
    int ans=0;
    map<string,int> ma;
    for(int i=0;i<n-1;i++){
        string tp="";
       
        tp=s[i];
        tp+=s[i+1];
        // cout<<tp<<" tpp\n";
        if(ma.find(tp)==ma.end()){
            ans++;
            ma[tp]=1;
            
        }
    }
    //ans++;
    cout<<ans<<"\n";
    
    
    


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}