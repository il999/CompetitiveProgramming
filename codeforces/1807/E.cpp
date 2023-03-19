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
    ll a[n];
    ll pre[n+1];
    pre[0]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        pre[i+1]=pre[i]+a[i];
    }
    int low=1;
    int high=n;
    int lastworking=1;
    while(low<high){
        int mid=(low+high)/2;
        ll query=0;
        cout<<"?"<<" "<<mid-low+1<<" ";
        for(int i=low;i<=mid;i++){
            cout<<i<<" ";
        }
        cout<<"\n";
        cout.flush();
        cin>>query;
        if(pre[mid]-pre[low-1]!=query){
            high=mid;
        }else{
            low=mid+1;
            lastworking=mid;
        }
    }
    
    cout<<"! "<<low<<"\n";
    cout.flush();
    
    

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
