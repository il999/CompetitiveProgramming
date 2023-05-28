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
#define pii pair<int,int>
#define pli pair<ll,int>

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
int ans=0;
vector<int> seen(200001,0);
vector<vector<array<int,2> > > v (200001,vector<array<int,2> >());
vector<array<int,2> > cost(200001,array<int,2> ());


void solve(){
    ans=0;
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        v[i].clear();
        seen[i]=0;
        cost[i][0]=1e9;
        cost[i][1]=1e9;
    }
    int a,b;
    //all drawn to vertexes get added to the tree is it?
    array<int,2> tp2;
    for(int i=0;i<n-1;i++){

        cin>>a>>b;
        
        tp2[0]=b;
        tp2[1]=i;
        
        v[a].push_back(tp2);
        tp2[0]=a;
        v[b].push_back(tp2);
    }
    
    priority_queue<array<int,3> ,vector<array<int,3> >,greater<array<int,3> > > q;
    int ans=0;
    array<int,3> tp;
    tp[0]=0;
    tp[1]=1;
    tp[2]=n+4;
    cost[1][0]=0;
    cost[1][1]=1e9;
    q.push(tp);
    while(!q.empty()){
        array<int,3> cur=q.top();
        q.pop();
        for(int i=0;i<v[cur[1]].size();i++){
            int lower=1;
            if(v[cur[1]][i][1]>cur[2]){
                lower=0;
            }
            if(cost[v[cur[1]][i][0]][0]>cur[0]+lower){
                cost[v[cur[1]][i][0]][0]=cur[0]+lower;
                cost[v[cur[1]][i][0]][1]=v[cur[1]][i][1];
                tp[0]=cost[v[cur[1]][i][0]][0];
                tp[1]=v[cur[1]][i][0];
                tp[2]=cost[v[cur[1]][i][0]][1];
                q.push(tp);

            }else if(cost[v[cur[1]][i][0]][0]==cur[0]+lower&&cost[v[cur[1]][i][0]][1]>v[cur[1]][i][1]){
                cost[v[cur[1]][i][0]][1]=v[cur[1]][i][1];
                tp[0]=cost[v[cur[1]][i][0]][0];
                tp[1]=v[cur[1]][i][0];
                tp[2]=cost[v[cur[1]][i][0]][1];
                q.push(tp);

            }
        }
        //cout<<cur[0]<<" "<<cur[1]<<" "<<cur[2]<<"\n";
        ans=cur[0];
    }
    //dfs(1,-1,0);
    cout<<ans<<"\n";


}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}