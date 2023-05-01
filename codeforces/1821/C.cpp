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
    string s;
    cin>>s;
    n=s.size();
    int par=1;
    vector<bool> inservice(n);
    int ans=1e9;
    for(int i=0;i<26;i++){
        vector<int> s1;
        int temp=0;
        for(int j=0;j<n;j++){
            if(s[j]-'a'==i){
                if(temp>0)
                    s1.push_back(temp);
                temp=0;
            }else{
                temp++;
            }
        }
        if(temp>0)s1.push_back(temp);
       
        int ptot=0;
        for(int j=0;j<s1.size();j++){
            int p=0;
            while(s1[j]>0){
                p++;
                s1[j]/=2;
            }
            ptot=max(ptot,p);
        }
        ans=min(ans,ptot);
    }
    cout<<ans<<"\n";

  
   


}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
