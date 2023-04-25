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
   ll n;
   cin>>n;
   ll a[n];
   for(int i=0;i<n;i++)cin>>a[i];
   vector<ll> neg;
   vector<ll> pos;
   bool zero=0;
   for(int i=0;i<n;i++){
    if(a[i]<0){
        neg.push_back(a[i]);
    }else{
        if(a[i]==0)zero=1;
        pos.push_back(a[i]);
    }
   }
   sort(pos.begin(),pos.end());
   sort(neg.begin(),neg.end());
  // cout<<"ans ";
   if(pos.size()>1&&neg.size()>1){
    cout<<max(pos[pos.size()-1]*pos[pos.size()-2],neg[0]*neg[1])<<"\n";
   }else if (pos.size()>1){
    cout<<pos[pos.size()-1]*pos[pos.size()-2]<<"\n";
   }else if (neg.size()>1){
    cout<<neg[0]*neg[1]<<"\n";
   }else if (zero){
    cout<<0<<"\n";
   }else{
    cout<<neg[0]*pos[0]<<'\n';
   }
   


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
