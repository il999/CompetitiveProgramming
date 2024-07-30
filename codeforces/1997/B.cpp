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
    cin>>n;
    string s[2];
    cin>>s[0]>>s[1];
    vector<bool> left(n);
    vector<bool> right(n);
    for(int i=0;i<n;i++){
        if(s[0][i]=='.'||s[1][i]=='.') left[i]=true;

        if(i!=0) left[i] = left[i]|left[i-1];
     //   cout<<left[i]<<"\n";
    }
    for(int i=n-1;i>=0;i--){
        if(s[0][i]=='.'||s[1][i]=='.') right[i]=true;
        if(i!=n-1) right[i] = right[i]|right[i+1];
    }
    int ans=0;
    for(int i=1;i<n-1;i++){
        if(s[0][i]=='.'&&((s[0][i-1]=='x'&&left[i-1]))&&((s[0][i+1]=='x'&&right[i+1]))&&s[1][i]=='.'){
            ans++;
        }
        //cout<<(s[i][0]=='.')<<" "<<((s[i-1][0]=='x'&&left[i-1]))<<" "<<(s[i+1][0]=='x'&&right[i+1])<<"\n";
        if(s[1][i]=='.'&&((s[1][i-1]=='x'&&left[i-1]))&&((s[1][i+1]=='x'&&right[i+1]))&&s[0][i]=='.'){
            ans++;
        }
    }
    cout<<ans<<"\n";



}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();

}