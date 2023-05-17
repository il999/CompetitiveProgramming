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
    for(int i=0;i<n;i++)cin>>a[i];
    vector<array<int,2> > v;
    for(int i=0;i<n;i++){
        array<int,2> tp;
        tp[0]=a[i];
        tp[1]=i;
        v.push_back(tp);
    }
    sort(v.begin(),v.end());
    vector<int> differences;
    for(int i =0;i<n;i++){
        if(abs(v[i][1]-i)>0)
            differences.push_back(abs(v[i][1]-i));

    }
    sort(differences.begin(),differences.end());
   vector<int> prim(n+1,1e9);
    for(int i=0;i<differences.size();i++){
        
        for(int j=2;j*j<=n;j++){
            int tot=0;
            while(differences[i]%j==0){
                tot++;
                differences[i]/=j;
            }

            prim[j]=min(prim[j],tot);
          //  primes[i].push_back(tot);
        }
        if(prim[differences[i]]==1e9)prim[differences[i]]=0;
        prim[differences[i]]--;
    }
   // cout<<prim[3]<<" suiii"\n
    ll ans=1;
    for(int i=2;i<=n;i++){
        while(prim[i]!=1e9&&prim[i]>0){
            
            ans*=i;
            prim[i]--;
        }
        if(prim[i]<0&&prim[i]==-differences.size()){
            ans*=i;
        }
    }
    cout<<ans<<"\n";
    


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}