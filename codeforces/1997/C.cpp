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
    string s;
    cin>>s;
    s[0]='(';
    int ans=0;
    int openbrackets=0;
    queue<int> q;
    for(int i=1;i<n;i+=2){
        if(openbrackets>0){
            openbrackets--;
            ans+=(i-1-q.front());
            q.pop();
        }else{
            openbrackets++;
            q.push(i-1);
        }
        if(s[i]=='('){
            openbrackets++;
            q.push(i);
        }
        else if(s[i]==')'){
            openbrackets--;
            ans+=(i-q.front());
            q.pop();
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