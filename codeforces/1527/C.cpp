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
    array<ll,2> ar;
    ll tp;
    for(int i=0;i<n;i++){
        cin>>tp;
        ar[0]=tp;
        ar[1]=i;
        v.push_back(ar);
    }
    sort(v.begin(),v.end());
    ll c=1;
    ll ans=0;
    map<ll,ll> spaces;
    map<ll,ll> total;
    for(int i=0;i<n;i++){
        if(spaces.find(v[i][0])==spaces.end()){
            spaces[v[i][0]]=0;
            total[v[i][0]]=0;
        }
        total[v[i][0]]++;
        spaces[v[i][0]]+=n-v[i][1]-1;
    }
    for(int i=0;i<n-1;i++){
        if(v[i][0]!=v[i+1][0]) continue;
        spaces[v[i][0]]-=(n-v[i][1]-1);
        total[v[i][0]]--;
       // int subtract=0;
       // ll th=(spaces[v[i][0]]+v[i][1]);
        ans+=(spaces[v[i][0]]+total[v[i][0]])*(v[i][1]+1);

    }
    cout<<ans<<"\n";

}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}