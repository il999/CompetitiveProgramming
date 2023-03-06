
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
    int n,k;
    cin>>n>>k;
    string a,b;
    cin>>a;
    cin>>b;
    string a1=a; 
    string b1=b;
    sort(a1.begin(),a1.end());
    sort(b1.begin(),b1.end());
    if(a1!=b1) {
        cout<<"NO\n";
        return;
    }
    
    int pos[26][2];
    for(int i=0;i<26;i++){
        pos[i][0]=1e9+7;
        pos[i][1]=-1e9+7;
    }
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]&&k>i&&n-k-1<i){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
}