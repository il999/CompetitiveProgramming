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

int divide(int x, int y)
{
    return mul(x, inv(y));
}
vector<int> bit1(200002,0);
int n;
void update(int x, int d) { for (int i = x; i <= n; i += i & -i) bit1[i] += d; }
    int query(int x) {
        int rtn = 0;
        for (int i = x; i; i -= i & -i) rtn += bit1[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) - query(x - 1); }
void solve(){
   
    cin>>n;
    int mi=0;
    int l,r;
    bit1.clear();

    int places[n+1];
    int a[n];
    for(int i=0;i<=n;i++){
        bit1[i]=0;
    }
    
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        if(a[i]>1){
            update(i+1,1);
        }
    }
    for(int i=0;i<n;i++) places[a[i]]=i+1;
    
    if(abs(places[2]-places[1])>1){
        //swap n and in between;
        cout<<places[n]<<" "<<min(places[2],places[1])+1<<"\n";
    }else{
       if(places[1]<places[n]){
            if(places[1]>places[2]){
                cout<<places[1]<<" "<<places[n]<<"\n";
            }else{
                cout<<places[2]<<" "<<places[n]<<"\n";
            }
       }else{
            if(places[1]<places[2]){
                cout<<places[1]<<" "<<places[n]<<"\n";
            }else{
                cout<<places[2]<<" "<<places[n]<<"\n";
            }
       }
    }
  //  cout<<ma<<" poo \n";
    

}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}