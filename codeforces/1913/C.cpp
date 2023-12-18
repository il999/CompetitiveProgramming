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
    int m;
    cin>>m;
    vector<int> x(31,0);

    while(m--){
        int t,v;
        cin>>t>>v;
        if(t==1){
            x[v]++;
        }else{
            vector<int> tp(31);
            for(int i=0;i<30;i++) tp[i]=x[i];
            for(int i=0;i<30;i++){
                if((v&(1<<i))!=0&&tp[i]==0){
                    cout<<"NO\n";
                    tp[0]=-9;
                    break;
                }else if((v&(1<<i))!=0){
                    tp[i]--;
                }
                tp[i+1]+=(tp[i])/2;
            }
            if(tp[0]!=-9){
                cout<<"YES\n";
            }
        }
    }

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

        int t=1;
        while(t--) {
            solve();
        }
}