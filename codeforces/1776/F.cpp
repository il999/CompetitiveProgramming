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
    int n,m;
    cin>>n>>m;
   // vector<int> in(n,0);
    
    int a,b;
    array<int,2> tp;
    vector<vector<array<int,2> > > v(n+1,vector<array<int,2> >());
    for(int i=0;i<m;i++){
        cin>>a>>b;
        tp[0]=a;
        tp[1]=i;
        v[b].push_back(tp);
        tp[0]=b;
        v[a].push_back(tp);
    }
    vector<int> ans(m,1);
    int mi=1e9;
    int in=0;
    for(int i=1;i<=n;i++){
        if(v[i].size()<mi){
            mi=v[i].size();
            in=i;
        }
    }
    for(int i=0;i<v[in].size();i++){
        ans[v[in][i][1]]=2;
    }
    if(m==((n*(n-1))/2)){
        cout<<3<<"\n";
        ans[v[in][0][1]]=3;
        for(int i=0;i<m;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    cout<<2<<"\n";
    for(int i=0;i<m;i++){
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