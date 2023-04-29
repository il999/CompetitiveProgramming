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
    if(n==1){
        cout<<"1\n";
        return;
    }else if(n==2){
        cout<<"1 2\n";
        return;
    }else if(n%2==1){
        cout<<"-1\n";
        return;
    }
    vector<int> ans;
    for(int i=n;i>=1;i-=2){
        ans.push_back(i-1);
        ans.push_back(i);
        cout<<i-1<<" "<<i<<" ";
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
