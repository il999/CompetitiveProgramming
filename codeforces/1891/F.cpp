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
vector<int> li;
vector<vector<int> > v (500001);
vector<int> position(500001);
vector<int> subtree(500001);
vector<ll> seg(4000004);
vector<ll> flag(4000004);
int n;
void dfs(int u){
    position[u]=li.size();
    li.push_back(u);
    subtree[u]=1;
    for(int i=0;i<v[u].size();i++){
        dfs(v[u][i]);
        subtree[u]+=subtree[v[u][i]];
    }
}
void pushflag(int v){
    if(flag[v]!=0){
        //flag[v]=0;
        flag[v*2]+=flag[v];
        flag[v*2+1]+=flag[v];
        flag[v]=0;
    }
}
void build(int v,int tl,int tr){
        if(tl==tr){
            seg[v]=0;
            flag[v]=0;
            return;
        }
        
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        seg[v]=0;
        flag[v]=0;
        //seg[v]=min(seg[v*2],seg[v*2+1]);
      //  cout<<seg[v][0]<<" "<<seg[v][1]<<"\n";
 
    }
    void update(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            seg[v] = 0;
            flag[v] = 0;
        } else {
            pushflag(v);
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos);
            else
                update(v*2+1, tm+1, tr, pos);
           // seg[v]=seg[v*2]+seg[v*2+1];
        }
    }
    void update2(int v, int tl, int tr, int l, int r,ll x){
        if(l>r){ 
            return;
        }
      //  cout<<l<<" "<<tl<<" "<<r<<" "<<tr<<"\n";
        if (l== tl && r==tr){
            flag[v] +=x;
            
        }else{
            pushflag(v);
            int tm= (tl+tr)/2;
            update2(v*2,tl,tm,l,min(tm,r),x);
            update2(v*2+1,tm+1,tr,max(tm+1,l),r,x);
        }
    }
    ll query(int v,int tl, int tr, int pos){
        if(tl==tr){
            return seg[v]+flag[v];
        }
        pushflag(v);
        int tm=(tl+tr)/2;
        if(pos<=tm){
            return query(v*2,tl,tm,pos);
        }else{
            return query(v*2+1,tm+1,tr,pos);
        }
        
    }
void solve(){
    int q;
    cin>>q;
    n=1;
    li.clear();
    vector<array<int,3> > queries (q,array<int,3> ());
    for(int i=0;i<q;i++){
        cin>>queries[i][0]>>queries[i][1];
        if(queries[i][0]==2) cin>>queries[i][2];
        else n++;
    }
    position.clear();
    subtree.clear();
    flag.clear();
    for(int i=0;i<=n;i++){
        v[i].clear();
    }
    int cur=2;
    for(int i=0;i<q;i++){
        if(queries[i][0]==1){
            v[queries[i][1]].push_back(cur);
            cur++;
        }
    }
    dfs(1);
    build(1,0,n-1);
    cur=2;
    for(int i=0;i<q;i++){
      //  cout<<"here\n";
        if(queries[i][0]==1){
            update(1,0,n-1,position[cur]);
            cur++;
        }else{
           // cout<<"her2\n";
            update2(1,0,n-1,position[queries[i][1]],position[queries[i][1]]+subtree[queries[i][1]]-1,queries[i][2]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<query(1,0,n-1,position[i+1])<<" ";
    }
    cout<<"\n";
}
int main()
{
 //   ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}