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
vector<bool> primes(10000001,1);
vector<int> prim;
void solve(){
   
   // int n;
   int n;
   cin>>n;
   //we are mergin three primes together
   //so always possible as long as we dont just have one prime
   //two primes done in two;
   int a[n];
   map<int,int> m;
  

   
   for(int i=0;i<n;i++){
    cin>>a[i];
    
    while(a[i]>1){
        if(primes[a[i]]){
            m[a[i]]++;
            a[i]=1;
            continue;
        }
        for(int j=0;j<prim.size();j++){
            while(a[i]%prim[j]==0){
                a[i]/=prim[j];
                m[prim[j]]++;
            }
            if(prim[j]>a[i]) continue;
        }
        
    }
    
   }
   int extra=0;
   int k=0;
   for(auto it : m){
    k+=it.second/2;
    extra+=it.second%2;
   }
   cout<<k+extra/3<<"\n";



}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
   for(int i=2;i*i<10000001;i++){
    if(primes[i]){

        for(int p=i*i;p<=10000001;p+=i)primes[p]=0;
    }
   }
   for(int i=2;i<1000001;i++){
    if(primes[i])prim.push_back(i);
   }
    int t;
    cin>>t;
    while(t--)
        solve();
}
