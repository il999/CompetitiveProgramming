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
   
   // int n;
   int n;
   cin>>n;
   int t;
   cin>>t;
    int a[n];
    int b[n];
   int ma=-1;
   int in=-1;
   //int a,b;
   for(int i=0;i<n;i++){
    cin>>a[i];
    //if()
   }
   for(int i=0;i<n;i++){
    cin>>b[i];
    if(t-a[i]-i>=0&&b[i]>ma){
        ma=b[i];
        in=i+1;
    }
   }
   cout<<in<<"\n";
   


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
