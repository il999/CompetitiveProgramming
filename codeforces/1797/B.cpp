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
    int a[n][n];
    int a2[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            a2[n-i-1][n-j-1]=a[i][j];
        }
    }
    int diff=0;
    //cout<<"printing\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a2[i][j]!=a[i][j])diff++;
            //cout<<a2[i][j]<<" ";
        }
       //cout<<"\n";
    }
    diff/=2;
   // cout<<diff<<"haha \n";
    if(diff>k)cout<<"NO\n";
    else{
        if((k-diff)%2==0|| diff==k){
            cout<<"YES\n";
        }else{
            int tp=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(n-i-1==i&&n-j-1==i){
                        tp=1;
                    }
                }
            }
            if(tp==1){
                cout<<"YES\n";
                return;
            }
            cout<<"NO\n";
        }
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
