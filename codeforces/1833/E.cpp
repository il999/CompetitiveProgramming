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
vector<int> a;
vector<vector<int> > connections(200001,vector<int> ());
vector<int> seen (200001);
bool boundary=0;
bool connected_into_others=0;
int run=0;
void dfs(int u,int last){
    seen[u]=run;
    if(a[u]==last){
        boundary=1;
        return;
    }
    
    if(seen[a[u]]!=run&&seen[a[u]]>0){
       // cout<<u<<" "<<a[u]<<"\n";
        connected_into_others=seen[a[u]];
    }
    if(0==seen[a[u]])
        dfs(a[u],u);
    
    
    
}
void solve(){
    int n;
    cin>>n;
    a.clear();
    int tp;
    a.push_back(0);
    for(int i=0;i<n;i++) {
        cin>>tp;
        connections[i+1].clear();
        a.push_back(tp);
        seen[i+1]=0;
    }
    
    int c=0;
    int ma=0;
    int ans=0;
    int mi=0;
    run=1;
    vector<int> pol(n+1,0);
    for(int i=0;i<n;i++){
        boundary=0;
        if(!seen[i+1]){
            //seen[i+1]=run;
            connected_into_others=0;
            dfs(i+1,-1);
            if(!connected_into_others){
                pol[i]=boundary;
                ma++;
                
            }else{
                pol[connected_into_others]+=boundary;
            }
        
            
            run++;
        }
        
    }
    int cur=0;
    int ma2=ma;
    for(int i=0;i<=n;i++){
        cur+=pol[i];
    }
    if(cur>0){
        ma2-=(cur-1);
    }
    cout<<ma2<<" ";
    cout<<ma<<"\n";

    
    
    


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}