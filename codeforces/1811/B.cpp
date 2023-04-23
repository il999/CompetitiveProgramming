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
int n;
int find_ring(int x, int y){
    //min of x, n-x+1,y,n-y+1;
    return min(min(x,n-x+1),min(y,n-y+1));
}
void solve(){
   
   // int n;
    int x1,y1,x2,y2;
    cin>>n>>x1>>y1>>x2>>y2;
    //n-y1+1;
    int t1=find_ring(x1,y1);
    int t2=find_ring(x2,y2);
    cout<<abs(t1-t2)<<"\n";
    

}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
