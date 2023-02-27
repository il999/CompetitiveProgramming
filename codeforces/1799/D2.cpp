
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
    ll n,k;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    vector<array<ll,2> > v (k,array<ll,2>());
    array<ll,2> tp;
    ll c,h;
    ll precold[n+1];
    precold[0]=0;
    for(int i=0;i<k;i++){
        cin>>c;
        v[i][0]=c;
      
        
    }
    for(int i=0;i<k;i++){
        cin>>h;
        v[i][1]=h;
    }
    ll dp[n+1][2];
    for(int i=0;i<=n;i++)
    {
        dp[i][1]=1e18+7;
    }
    vector<ll> ar(k+1,-1);
    dp[0][0]=0;
    dp[0][1]=0;
    for(int i=0;i<n;i++){
        dp[i+1][0]=min(dp[i][1],dp[i][0])+v[a[i]][0];
        precold[i+1]=precold[i];
        if(i>0&&a[i]==a[i-1])precold[i+1]+=v[a[i]][1];
        else precold[i+1]+=v[a[i]][0];
        if(ar[a[i]]!=-1)
        {
            //one before actual
            dp[i+1][1]=min(dp[ar[a[i]]+1][0],dp[ar[a[i]]+1][1])+v[a[i]][1]+precold[i]-precold[ar[a[i]]+1];
           // if()
            dp[i+1][1]=min(dp[i+1][1],dp[ar[a[i]]+2][1]+precold[i]-precold[ar[a[i]]+2]+v[a[i]][1]);
            //or we could use the hot of the ones before so we can also check 
        }
        if(i>=2&&a[i-2]==a[i]&&dp[i][1]<1e18+7){
            dp[i+1][1]=min(dp[i][1]+v[a[i]][1],dp[i+1][1]);
        }
    
        ar[a[i]]=i;
    }
    cout<<min(dp[n][0],dp[n][1])<<"\n";
    
    
}
int main()
{
     ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
}