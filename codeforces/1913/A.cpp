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
    int fromback[n+1];
    fromback[n]=0;
    int ten=1;
    for(int i=n-1;i>=0;i--){
        fromback[i]=fromback[i+1]+(s[i]-'0')*ten;
        ten*=10;
    }
    int fromstart[n+1];
    fromstart[0]=s[0]-'0';
    for(int i=1;i<n;i++){
        fromstart[i]=fromstart[i-1]*10+(s[i]-'0');
    }
    for(int i=0;i<n-1;i++){
     //   cout<<fromstart[i]<<" "<<fromback[i+1]<<"\n";
        if(fromstart[i]<fromback[i+1]&&fromstart[i]!=0&&fromback[i+1]!=0&&s[0]!='0'&&(s[i+1]!='0')){
            cout<<fromstart[i]<<" "<<fromback[i+1]<<"\n";
            return;
        }
    }
    cout<<-1<<"\n";

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

        int t;
        cin>>t;
        while(t--) {
            solve();
        }
}