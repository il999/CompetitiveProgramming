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
   int n,k;
   cin>>n>>k;
   int ones=0;
   int minusones=n;

   for(int i=0;i<=n;i++){
    int ans=0;
    if(ones>0){
        ans+=ones*(ones-1)/2;
    }
    if(minusones>0){
        ans+=minusones*(minusones-1)/2;
    }
    if(ans==k){
        cout<<"YES\n";
        for(int j=0;j<ones;j++){
            cout<<"1 ";
        }
        for(int j=0;j<minusones;j++){
            cout<<"-1 ";
        }
        cout<<"\n";
        return;
    }
    ones++;
    minusones--;
   }
   cout<<"NO\n";
   


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
