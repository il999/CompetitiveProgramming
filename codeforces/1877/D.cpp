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
    vector<array<int,2> > v(n,array<int,2>());
    for(int i=1;i<=n;i++){
        cin>>v[i-1][0];
        v[i-1][1]=n-i;
    }
    vector<int> pos(n+1);
    sort(v.rbegin(),v.rend());
    for(int i=0;i<n;i++){
        v[i][1]=n-v[i][1];
        pos[v[i][1]]=n-i-1;
    }
    vector<bool> possible(n+1,1);
    int total=0;
    int left=n-1;
    for(int i=0;i<n;i++){
        for(int j=1;j*j<=v[i][1];j++){
            if((v[i][1]%j)==0){
                if(possible[j]){
                    total=add(total,mul(v[i][0],binpow(2,left)));
                    left--;
                    possible[j]=0;
                }
                if(possible[v[i][1]/j]){
                    total=add(total,mul(v[i][0],binpow(2,left )));
                    possible[v[i][1]/j]=0;
                    left--;
                }
            }
        }
        if(possible[v[i][1]]){
            total=add(total,mul(v[i][0],binpow(2,left)));
            left--;
            possible[v[i][1]]=0;
        }
    }
    cout<<total<<"\n";
    
}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
   // cin>>t;
    while(t--)
        solve();
}