
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
    int n;
    int m;
    string a;
    string b;
    cin>>a;
    cin>>b;
    n=a.size();
    m=b.size();
    string temp="";
    for(int i=0;i<n-1;i++){
        temp="";
        temp+=a[i];
        temp+=a[i+1];
        for(int j=0;j<m-1;j++){
            string temp2="";
            temp2+=b[j];
            temp2+=b[j+1];
            if(temp2==temp){
                cout<<"YES\n";
                cout<<'*'<<temp<<"*"<<"\n";
                return;
            }
        }
    }
    if(a[0]==b[0]){
        cout<<"YES\n";
        cout<<a[0]<<"*\n";
        return;
    }
    if(a[n-1]==b[m-1]){
        cout<<"YES\n";
        cout<<'*'<<b[m-1]<<"\n";
        return;
    }
   // cout<<a<<" gskgdh \n";
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