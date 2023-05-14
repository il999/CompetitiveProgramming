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
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    //for(int i=0;i<n-1;i++) ans+=abs(a[i]-a[i+1]);
    int nnew=n;
    int last=a[0];
    for(int i=1;i<n-1;i++){
        while(i<n-2&&a[i]==a[i+1]){
            nnew--;
            i++;
        }
        if((a[i]>=last)==(a[i]<=a[i+1])||a[i]==last||(i==n-2&&a[i]==a[i+1]))nnew--;
        else last=a[i];
    }
    if(nnew==2&&a[0]==a[n-1])cout<<1<<"\n";
    else cout<<nnew<<"\n";
    
    


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
