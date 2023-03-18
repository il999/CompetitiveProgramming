
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
    //big can go with 2 small
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int zeros=0;
   for(int i=0;i<n;i++){
        if(a[i]==0)zeros++;
   }
   
    if(zeros>(n/2+n%2)){
        int ans=2;
        int one=0;
        int other=0;
        for(int i=0;i<n;i++){
            if(a[i]==1)one++;
        }
        if(one+zeros==n&&zeros!=n){
            cout<<2<<"\n";
        }else{
            cout<<1<<"\n";
        }
        
       
    }else{
        cout<<0<<"\n";
    }
   // cout<<other<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}