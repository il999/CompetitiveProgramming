
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
    string s[2*(n-1)];
    for(int i=0;i<2*(n-1);i++)cin>>s[i];
    int ma=n-1;
    vector<char> c;
    vector<string> v;
    for(int i=0;i<2*(n-1);i++){
        if(ma==s[i].size())v.push_back(s[i]);
        if(s[i].size()==1)c.push_back(s[i][0]);
    }
    if(c[0]!=c[1]){

        cout<<"NO\n";
        return;
    }
    string p=v[0]+c[0];
    string d=c[0]+v[1];
    reverse(d.begin(),d.end());
    if(d==p)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";


 
    
    
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
}