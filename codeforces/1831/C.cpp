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
        int x=cur[0];
        int y=cur[1];
        int z=cur[2];
        for(int i=0;i<v[y].size();i++){
            int lower=1;
            int curedge=v[y][i][1];
            if(curedge>z){
                lower=0;
            }
            int u=v[y][i][0];
            
            if(cost[u][0]>x+lower){
                cost[u][0]=x+lower;
                cost[u][1]=curedge;
                tp[0]=cost[u][0];
                tp[1]=u;
                tp[2]=cost[u][1];
                q.push(tp);

            }else if(cost[u][0]==x+lower&&cost[u][1]>curedge){
                cost[u][1]=curedge;
                tp[0]=cost[u][0];
                tp[1]=u;
                tp[2]=cost[u][1];
                q.push(tp);

            }
        }
        //cout<<x<<" "<<y<<" "<<z<<"\n";
        ans=x;
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