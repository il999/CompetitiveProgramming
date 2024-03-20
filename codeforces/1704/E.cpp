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
using namespace std;
#define int long long
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

int divide(int x, int y) {
    return mul(x, inv(y));
}
struct BIT {
    int n, rtn; // rtn might need to be LLed
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1,0) {}
    void update(int x, int d) { for (int i = x; i <= n; i += i & -i)bit[i]= add(bit[i],d); }
    int query(int x) {
        rtn = 0;
        for (int i = x; i; i -= i & -i) rtn = add(bit[i],rtn);
        return rtn;
    }
    int query(int x, int y) { return query(y) - query(x - 1); }
};
int thing=0;
void dfs(int u,vector<bool>& vis,vector<vector<int> >& v,vector<int>& a,vector<int>& incoming,vector<bool>& changed){
    vis[u]=1;
    for(int i=0;i<v[u].size();i++){
        if(!vis[v[u][i]]) {
            if(a[u]!=0&&a[v[u][i]]==0){
                a[v[u][i]]=1ll;
                changed[a[v[u][i]]]=1;
                thing++;

            }
            dfs(v[u][i],vis,v,a,incoming,changed);
        }
    }
}
void solve() {

    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<vector<int> > v(n,vector<int>());
    vector<vector<int> > v2(n,vector<int>());
    bool waszero[n];
    vector<bool> hadvalue(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i])hadvalue[i]=1;
        //a[i]%=MOD;
    }
    int x,y;
    vector<int> incoming(n);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        x--;y--;
        v[x].push_back(y);
        v2[y].push_back(x);
        incoming[y]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        vector<int> p;
        for(int j=0;j<n;j++)p.push_back(a[j]);
        bool finished =1;
        for(int j=0;j<n;j++){
            if(p[j]>0){
                finished=0;
                a[j]--;
                for(int k=0;k<v[j].size();k++)a[v[j][k]]++;
            }
        }
        if(finished){
            cout<<i<<"\n";
            return;
        }
    }
    priority_queue<array<int,2>,vector<array<int,2> >, greater< > > pq;
    vector<int> origin(n);
    for(int i=0;i<n;i++){
        if(incoming[i]==0) {
            //cout<<"added\n";
            pq.push({a[i], i});
        }
        origin[i]=incoming[i];

    }
    vector<bool> changed(n);
    BIT fen(n+2);
  //  int ans=0;
 //   cout<<"why not here\n";
   // int ans=0;
    thing=0;


    //haszerochild;
    while(!pq.empty()){
        int u = pq.top()[1];
        int toadd = pq.top()[0];
        toadd -= fen.query(u+1);
       // toadd=max(1,toadd);
       // cout<<u<<" "<<toadd<<" "<<a[u]<<"\n";
        ans=add(toadd,ans);
        fen.update(1,toadd);
        pq.pop();
      //  cout<<toadd<<"\n";
        for(int i = 0;i<v[u].size();i++){
         //  cout<<"her\n";
            int tp = fen.query(v[u][i]+1);
            a[v[u][i]] = a[v[u][i]]+(tp*(incoming[v[u][i]]-1));

            incoming[v[u][i]]--;

            if(incoming[v[u][i]]==0){
                pq.push({a[v[u][i]],v[u][i]});
                //incoming[v[u][i]]=-1;
            }
            fen.update(v[u][i]+1,-tp);
            fen.update(v[u][i]+2,+tp);
        }

    }
    cout<<(ans+n)%MOD<<"\n";

}

signed main(){
   // ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

