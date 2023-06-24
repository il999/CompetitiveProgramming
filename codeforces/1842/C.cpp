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
    int n;
    cin>>n;
    int col[n];
    vector<int> maxc(n+1 ,-1);
    for(int i=0;i<n;i++)cin>>col[i];
    int dp[n+1];
    
    dp[0]=0;
    for(int i=0;i<n;i++){
        dp[i+1]=dp[i];
        if(maxc[col[i]]!=-1){
            
            dp[i+1]=max(dp[i+1],dp[maxc[col[i]]]+i-maxc[col[i]]+1);
            if(dp[i]>dp[maxc[col[i]]]+i-maxc[col[i]]){
                maxc[col[i]]=i;
            }
        }else{
            maxc[col[i]]=i;
        }
        
        
    }
    cout<<dp[n]<<"\n";
    //for()
    
    


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}