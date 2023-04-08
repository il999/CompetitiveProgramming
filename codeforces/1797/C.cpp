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
   
    int n,m;
    cin>>n>>m;
    int possible=0;
   // int vector<int> possible;
    int ans=0;
    cout<<"? 1 1\n";
    cout.flush();
    cin>>ans;
    int r=n+4;
    int c=m+4;
    if(ans+1<=n){
        cout<<"? "<<ans+1<<" "<<1<<"\n";
        cout.flush();
        cin>>c;
    }
    if(ans+1<=m){

    
        cout<<"? "<<1<<" "<<ans+1<<"\n";
        cout.flush();
        cin>>r;
    }
    if(c<r){
        cout<<"! ";
        cout<<ans+1<<" "<<1+c<<"\n";
    }else{
        cout<<"! ";
        cout<<1+r<<" "<<ans+1<<"\n";
    }
    
    

}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
