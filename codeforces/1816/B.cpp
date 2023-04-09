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
   
    int n;
    cin>>n;
    int ans[2][n];
    int it=n;
    int it2=2*n;
   

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            if(it2==2*n-1){
                it2--;
            }
            if((i+j)%2==0){
                ans[j][i]=it2;
                it2--;
            }else{
                ans[j][i]=it;
                it--;
            }
        }
    }
     ans[1][n-1]=2*n-1;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++)cout<<ans[i][j]<<" ";
        cout<<"\n";
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
