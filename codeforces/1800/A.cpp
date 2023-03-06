
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
    string s;
    cin>>s;
    char alph[4]={'m','e','o','w'};
    char alph2[4]={'M','E','O','W'};
    int in=0;
    if(s[0]!='M'&&s[0]!='m'){
        cout<<"NO\n";
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]!=alph[in]&&s[i]!=alph2[in]){
            in++;
            if(in==4){
                cout<<"NO\n";
                return;
            }
            if(s[i]!=alph[in]&&s[i]!=alph2[in]){
                cout<<"NO\n";
                return;
            }
        }
    }
    if(in!=3){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    
    int t;
    cin>>t;
    while(t--)
        solve();
}