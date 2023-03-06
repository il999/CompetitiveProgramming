
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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> upper(26);
    vector<int> lower(26);
    int a='a';
    int b='A';
    int burles=0;
    for(int i=0;i<n;i++){
        if(s[i]<='Z'){
            if(lower[s[i]-'A']>0){
                lower[s[i]-'A']--;
                burles++;
            }else upper[s[i]-'A']++;
            
        }else{
            if(upper[s[i]-'a']>0){
                upper[s[i]-'a']--;
                burles++;
            }else lower[s[i]-'a']++;
        }
    }
    for(int i=0;i<26;i++)
    {
        while(upper[i]>1&&k>0){
            upper[i]-=2;
            burles++;
            k--;
        }
        while(lower[i]>1&&k>0){
            lower[i]-=2;
            burles++;
            k--;
        }
    }
    cout<<burles<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
}