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
    int in=0;
    int r=0;
    //if(n==1)
    for(int i=0;i<n;i++)cin>>a[i];
    if(n==1){
        cout<<"1\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(a[i]==n){
            in=i;
        }   
    }
    r=in-1;
    if(r==-1){
        for(int i=0;i<n;i++){
            if(a[i]==n-1)r=i-1;
        }
    }
  //  vector<int> ne;
   vector<int> cur (n,-1);
   int l=0;
    for(int i=0;i<=r;i++){
         vector<int> ne;
         for(int j=r+1;j<n;j++)ne.push_back(a[j]);
         for(int j=r;j>=i;j--) ne.push_back(a[j]);
         for(int j=0;j<i;j++) ne.push_back(a[j]);
         for(int j=0;j<n;j++){
            if(cur[j]>ne[j]) break;
            if(cur[j]<ne[j]){
                l=i;
                cur=ne;
                break;
            }
         }
    }
    if(r==n-2){
        vector<int> ne;
        ne.push_back(a[n-1]);
        for(int j=0;j<n-1;j++)ne.push_back(a[j]);
        for(int j=0;j<n;j++){
            if(cur[j]>ne[j]) break;
            if(cur[j]<ne[j]){
                //l=i;
                cur=ne;
                break;
            }
         }
    }
    //cout<<l<<int
  //  cout<<"ans "<<"\n";
    for(int i=0;i<n;i++){
        cout<<cur[i]<<" ";
    }
    cout<<"\n";


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}