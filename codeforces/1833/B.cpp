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
    int k;
    cin>>k;
    int a[n];
    int b[n];
    vector<array<int,2> > v(n,array<int,2>());
    int bnew[n];
    array<int,2> tp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        tp[0]=a[i];
        tp[1]=i;
        v[i]=tp;
        
    }
    for(int i=0;i<n;i++)cin>>b[i];
    sort(v.begin(),v.end());
    sort(b,b+n);
    for(int i=0;i<n;i++){
        bnew[v[i][1]]=b[i];
    }
    for(int i=0;i<n;i++){
        cout<<bnew[i]<<" ";
    }
    cout<<"\n";
    
    
    


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}