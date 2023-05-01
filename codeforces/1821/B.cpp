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
    int a[n];
    int b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for (int i=0;i<n;i++)cin>>b[i];
    int mi=1e9;
    int in=0;
    int ma=-1;
    int in2=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]&&b[i]<mi){
            mi=b[i];
            in=i;
        }
        if(a[i]!=b[i]&&b[i]>ma){
            ma=b[i];
            in2=i;
        }
    }
    while(in>0&&(b[in-1]==mi||(b[in-1]==a[in-1]&&b[in]>b[in-1]))){
        mi=b[in-1];
        in--;
    }
    while(in2<n-1&&(b[in2+1]==ma||(b[in2+1]==a[in2+1]&&b[in2+1]>b[in2]))){
        ma=b[in2+1];
        in2++;
    }
   cout<<in+1<<" "<<in2+1<<"\n";


}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
