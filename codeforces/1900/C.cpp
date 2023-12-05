#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <cassert>
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

vector<array<int,3> > v ( 300001,array<int,3>());
string s;
int n;
const int inf = 1e9;
vector<int> cost(300001,inf);
void costdfs(int u ){
   // cout<<u<<" ";
   // cout<<"hello\n";
    if(cost[u]!=inf){
        return;
    }

    int parent=v[u][2];
    if(u==2){
        //cout<<v[u][2]<<"what da hell am i doing\n";

    }
 //   cout<<v[parent][0]<<" "<<v[parent][1]<<"\n";
    if(v[parent][0]==u){
        costdfs(parent);
       // cout<<<"\n";
        if(s[parent-1]=='L'){
          //  cout<<"cheap\n";
            cost[u]=cost[parent];

        }else{

            cost[u]=cost[parent]+1;
           // cout<<u<<" "<<cost[u]<<"\n";
        }
    }
    else if (v[parent][1]==u){
        costdfs(parent);
        if(s[parent-1]=='R'){
           // cout<<"cheap\n";
            cost[u]=cost[parent];
        }else{
            cost[u]=cost[parent]+1;
          //  cout<<u<<" "<<cost[u]<<"\n";
        }
    }
}
void solve() {
    cin>>n;
  //  string s;
    cin>>s;
    int a,b;
    for(int i=0;i<=n;i++){
        for(int j=0;j<3;j++){
            v[i][j]=0;
        }
        cost[i]=inf;
    }
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a!=0){
            v[i+1][0]=a;
            //0  left 1 right 2 parent;
            v[a][2]=i+1;
        }
        if(b!=0){
            v[i+1][1]=b;
            v[b][2]=i+1;
        }
    }
    int ans=1e9;
    cost[1]=0;
    for(int i=1;i<=n;i++){
        if(v[i][0]==0&&v[i][1]==0){
           // cout<<v[i][2]<<" parent\n";
            costdfs(i);
           // cout<<cost [i]<<" here\n";
            ans=min(ans,cost[i]);
        }
    }
  //  for(int i=0;i<n;i++) cout<<cost[i+1]<<" ";
   //cout<<"\n";
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