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
using namespace std;
const int MOD=998244353;
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
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<array<int,2> > ma(n+1,array<int,2>());
    vector<array<int,2> > co(n+1,array<int,2>());
    ma[0]={0,0};
    co[0]={1,1};
    for(int i =1;i<=n;i++){
        ma[i][0] = max({a[i-1]+ma[i-1][0],abs(a[i-1]+ma[i-1][1]),abs(a[i-1]+ma[i-1][0])});
        if(a[i-1]+ma[i-1][0]==ma[i][0]){
            co[i][0]= add(co[i-1][0],co[i][0]);
        }
        if(ma[i-1][1]!=ma[i-1][0]&&abs(a[i-1]+ma[i-1][1])==ma[i][0]){
            co[i][0]= add(co[i-1][1],co[i][0]);
        }
        if(abs(a[i-1]+ma[i-1][0])==ma[i][0]){
            co[i][0]= add(co[i-1][0],co[i][0]);
        }
        if(ma[i-1][1]!=ma[i-1][0]&&(a[i-1]+ma[i-1][1])==ma[i][0]) co[i][0]= add(co[i-1][1],co[i][0]);
        ma[i][1] = ma[i-1][1]+a[i-1];
        if((ma[i-1][1]!=ma[i-1][0])&&a[i-1]+ma[i-1][0]==ma[i][1]){
            co[i][1]= add(co[i-1][0],co[i][1]);
        }
        if(abs(a[i-1]+ma[i-1][1])==ma[i][1]){
            co[i][1]= add(co[i-1][1],co[i][1]);
        }
        if(ma[i-1][1]!=ma[i-1][0]&&abs(a[i-1]+ma[i-1][0])==ma[i][1]){
            co[i][1]= add(co[i-1][0],co[i][1]);
        }
        if((a[i-1]+ma[i-1][1])==ma[i][1]) co[i][1]= add(co[i-1][1],co[i][1]);
      //  cout<<co[i][0]<< " "<<co[i][1]<< "hello\n";
    }
    cout<<co[n][0]<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}