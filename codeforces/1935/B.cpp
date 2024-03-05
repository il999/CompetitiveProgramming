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

int divide(int x, int y) {
    return mul(x, inv(y));
}
void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int mexfront[n+1];
    int mexback[n+1];
     mexback[n]=0;
     mexfront[0]=0;
     vector<bool> mex1(n+3);
     for(int i=0;i<n;i++){
         mexfront[i+1]=mexfront[i];
         mex1[a[i]]=1;
         while(mex1[mexfront[i+1]]){
             mexfront[i+1]++;
         }
     }
     vector<bool> mex2(n+3);
     for(int i=n-1;i>=0;i--){
         mexback[i]=mexback[i+1];
         mex2[a[i]]=1;
         while(mex2[mexback[i]]){
             mexback[i]++;
         }

     }
     for(int i=1;i<n;i++){
         if(mexfront[i]==mexback[i]){
             cout<<2<<"\n";
             cout<<1<<" "<<i<<"\n";
             cout<<i+1<<" "<<n<<"\n";
             return;
         }
     }
     cout<<"-1\n";

}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
