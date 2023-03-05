
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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    //score only useful fi it allows current score length at least equals the value of a[i]
    int cur_len=1;
    cout<<"1 ";
    int start=0;
    for(int i=1;i<n;i++){
        
        if(a[i]>cur_len)
        {
            cur_len++;
        }else if(a[i]==cur_len){
            start++;
        }
        if(a[start]<cur_len){
            start++;
            cur_len--;
        }
        cout<<cur_len<<" ";
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