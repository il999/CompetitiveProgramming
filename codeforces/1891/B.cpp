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
ll add(ll x, ll y)
{
    return ((x + y));
}
 
ll mul(int x, int y)
{
    return x * 1ll * y ;   
}
 
ll binpow(ll x, ll y)
{
    ll z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}
 

void solve(){
    int n,q1;
    cin>>n>>q1;
    ll a[n],q[q1];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<q1;i++) cin>>q[i];
    vector<int> vnew;
    int possible=30;
    for(int i=0;i<q1;i++){
        if(q[i]<=possible){
            possible=q[i]-1;
            vnew.push_back(q[i]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<vnew.size();j++){
            if((a[i]%(binpow(2,vnew[j])))==0){
                a[i]+=binpow(2,vnew[j]-1);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
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