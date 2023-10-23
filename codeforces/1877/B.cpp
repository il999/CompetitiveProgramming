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
    int n,p;
    cin>>n>>p;
    vector<array<int,2> > v (n,array<int,2>());
    for(int i=0;i<n;i++){
        cin>>v[i][1];
    }
    for(int j=0;j<n;j++){
        cin>>v[j][0];
    }
    array<int,2> tp;
    priority_queue<array<int,2>, vector<array<int,2> >, greater<array<int,2> > > pq;
    sort(v.begin(),v.end());
    tp[0]=p;
    tp[1]=5*n;
    pq.push(tp);
    ll total=0;
    for(int i=0;i<n;i++){
        array<int,2> cur = pq.top();
        pq.pop();
        cur[1]--;
        total+=cur[0];
        if(cur[1]!=0){
            pq.push(cur);
        }
        
        pq.push(v[i]);
    }
    cout<<total<<"\n";

}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}