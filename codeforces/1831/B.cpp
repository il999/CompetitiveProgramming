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
    int a[n];
    int b[n]; 
    for(int i=0;i<n;i++) cin>> a[i];
    for (int i=0;i<n;i++ )cin>> b[i];
    vector<int> ma(2*n+1);
    vector<int> mb(2*n+1);
    //int ma=1;
    int cur=1;
    ma[a[0]]=1;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            cur++;
            ma[a[i]]=max(ma[a[i]],cur);
        }else{
            cur=1;
            ma[a[i+1]]=max(ma[a[i+1]],1);
        }
    }
  //  ma[a[n-1]]=cur
    cur=1;
    mb[b[0]]=1;
     for(int i=0;i<n-1;i++){
        if(b[i]==b[i+1]){
            cur++;
            mb[b[i]]=max(mb[b[i]],cur);
        }else{
            cur=1;
            mb[b[i+1]]=max(mb[b[i+1]],1);
        }
    }
    int ans=1;
    for(int i=0;i<=2*n;i++){
       ans=max(ma[i]+mb[i],ans);
    }
    cout<<ans<<"\n";
   



}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}