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
  
    string s;
    cin>>s;
    int n=s.size();
    string news=s;
    
    for(int i=1;i<n;i++){
        if(news[i]=='?'&&news[i-1]=='1'){
            news[i]='1';
        }
    }
    for(int i=n-2;i>=0;i--){
        if(news[i]=='?'&&news[i+1]=='1'){
            news[i]='1';
        }
    }
    for(int i=0;i<n;i++)if(news[i]=='?')news[i]='0';

    cout<<news<<"\n";


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}