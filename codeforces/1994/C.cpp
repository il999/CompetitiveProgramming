#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <stack>
#include <chrono>
#include <numeric>
using namespace std;
const int MOD =998244353;
#define int long long
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

void solve() {
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int pre[n+2];
    pre[n]=0;
    for(int i=n-1;i>=0;i--){
        pre[i]=a[i]+pre[i+1];
    }
    vector<int> zero(n+1);
    vector<array<int,2> > add;
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]>x) {
            zero[i]=i+1;
            continue;
        }
        int low =i;
        int high = n;
        //first for which pre[i]-pre[j]>x
        while(low<high){
            int mid= (low+high)/2;
            if(pre[i]-pre[mid+1]<=x) low=mid+1;
            else high=mid;
        }
       // cout<<"LOW: "<<low<<"\n";
        if(low!=n){
            if(i>0)
                zero[low]+=(zero[i-1]+1);
            else zero[low]++;
        }
    }
  //  cout<<ans<<"\n";
    ans=0;
    //for(int i=0;i<n;i++) cout<<zero[i]<<" ";
    for(int i=0;i<n;i++){
        ans+=(i+1)-zero[i];
    }
    cout<<ans<<"\n";



}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();

}