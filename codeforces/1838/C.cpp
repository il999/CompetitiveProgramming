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

int divide(int x, int y)
{
    return mul(x, inv(y));
}

void solve(){
    int n,m;
    cin>>n>>m;
    bool flip=0;
    
    int a[n+1][m+1];
    for(int i=1;i<=n;i++){
        
            for(int j=1;j<=m;j++){
                a[i][j]=m*(i-1)+j;
            }
          
        
    }
    
    if(m%2==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
        return;
    }
        for(int i=2;i<=n;i+=2){
            for(int j=1;j<=m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
        for(int i=1;i<=n;i+=2){
            for(int j=1;j<=m;j++){
                cout<<a[i][j]<<" ";
            }
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