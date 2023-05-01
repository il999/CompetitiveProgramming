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
   
   // int n;
   int n;
   cin>>n;
   int k;
   cin>>k;
   int a[n];
   for(int i=0;i<n;i++)cin>>a[i];
   int mo[n];
   int notzero=0;
   for(int i=0;i<n;i++){
    mo[i]=(abs(a[i]-i-1)%k);
    if(mo[i]>0)notzero++;
   }
   //cout<<"here";
   if(0==notzero){
    cout<<"0\n";
    return;
   }
 // cout<<n<<"ADFDA";
   if(notzero==2){
    vector<int> v;
    for(int i=0;i<n;i++){
        if(mo[i]>0){
            v.push_back(i);
        }

    }
    if(abs(a[v[0]]-v[1]-1)%k==0&&abs(a[v[1]]-v[0]-1)%k==0){
        cout<<"1\n";
        return;
    }
   }
   cout<<"-1\n";
   
   


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
