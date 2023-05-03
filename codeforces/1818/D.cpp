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

vector<vector<int > > v (2001,vector<int>());
map<int,int> bridge;
vector<bool> seen;
vector<int> tin,low;
bool there=0;
int timer=0;
 void dfs(int u, int p=-1){
       // cout<<tin[];
      // cout<<"here"<<u<<"\n";
        seen[u]=1;
        tin[u] = low[u] = timer++;
        for (int to: v[u]) {
           // int to=to1[0];
            if(to==p) continue;
            if (seen[to]){
                low[u] = min(low[u], tin[to]);
            } else {
                dfs(to,u);
                //cout<<tin[u]<<"\n";
                low[u] = min(low[u], low[to]);
                if (low[to] > tin[u]) {
                  
                    bridge[to*2001+u]=1;
                    bridge[u*2001+to]=1;
                }
            }
        }
     
    }
void solve(){
    //timer=0;
    int n;
    cin>>n;
    int m;
    cin>>m;
    timer=0;
    for(int i=0;i<=n;i++){
        v[i].clear();
    }
    seen.assign(n+1,0);
    tin.assign(n+1,-1);
    low.assign(n+1,-1);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
       // array<int,2 > tp;
        v[a].push_back(b);
       // tp[0]=a;
        v[b].push_back(a);

    }
    
   // cout<<"WWWOWOW\n";
    //seen.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(v[i].size()>=4){
            queue<vector<int> > q;
            vector<int> tp;
            timer=0;
           bridge.clear();
           seen.assign(n+1,0);
           tin.assign(n+1,-1);
          low.assign(n+1,-1);
            dfs(i);
           // q.push(tp);
            for(int x=0;x<v[i].size();x++){
                
                if(bridge.find(i*2001+v[i][x])==bridge.end()){
                    tp.clear();
                    tp.push_back(i);
                    tp.push_back(v[i][x]);
                    q.push(tp);
                    while(!q.empty()){
                        tp=q.front();
                        q.pop();
                        int u = tp[tp.size()-1];
                        for( int j =0; j<v[u].size();j++){
                            
                                
                                
                            if(tp.size()>=3&&v[u][j]==i){
                                map<int,int> ma;
                                for(int k=0;k<tp.size();k++){
                                    ma[tp[k]]=1;
                                }
                                int found=0;
                                cout<<"YES\n";
                                cout<<tp.size()+2<<"\n";
                                for(int p=0;p<v[i].size();p++){
                                    if(ma.find(v[i][p])==ma.end()){
                                        found++;
                                        cout<<i<<" "<<v[i][p]<<"\n";
                                        if(found==2) break;
                                    }
                                }
                                for(int p=0;p<tp.size()-1;p++){
                                    cout<<tp[p]<<" "<<tp[p+1]<<"\n";
                                }
                                cout<<tp[0]<<" "<<tp[tp.size()-1]<<"\n";
                                return;
                                
                            }else if(v[u][j]!=v[i][x]&&(tp[tp.size()-2]!=v[u][j])){
                                tp.push_back(v[u][j]);
                                q.push(tp);
                                tp.pop_back();
                            }
                            
                        }
            }
            }
            }
        }
    }
    cout<<"NO\n";
    


}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
