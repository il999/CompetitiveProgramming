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
    vector<array<ll,2> > v;
    array<ll,2> tp;
    ll thing;
    for(int i=0;i<n;i++){
        cin>>thing;
        tp[0]=thing;
       // cin>>tp[i];
        tp[1]=i;
        v.push_back(tp);
    }
    vector<ll> ans(n);
    sort(v.begin(),v.end());
    ll total=0;
    ll forward[n];
    ll backward[n];
    forward[0]=v[0][0];
    backward[n-1]=v[n-1][0];

    for(int i=1;i<n;i++){
        forward[i]=forward[i-1]+v[i][0];
    }
    for(int i=n-2;i>=0;i--){
        backward[i]=backward[i+1]+v[i][0];
    }
    for(int i=0;i<n;i++){
        ans[v[i][1]]=((i+1)*v[i][0]-forward[i]+i+1)-((n-i-1)*v[i][0]-backward[i]+v[i][0]-n+i+1);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
   

   

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}