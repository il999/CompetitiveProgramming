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

int divide(int x, int y) {
    return mul(x, inv(y));
}
int n;
array<int,2> destination(int row, int col, vector<string>& s){
    if(row<0||row>1||col<0||col>=n){
        return {-1,-1};
    }
    if(s[row][col]=='>')
        return{row,col+1};
    if(s[row][col]=='<')
        return {row,col-1};


}
void dfs(vector<bool>& visited,int u,vector<vector<int> >& v){
    visited[u]=1;
    for(int i=0;i<v[u].size();i++){
        if(!visited[v[u][i]]){
            dfs(visited,v[u][i],v);
        }
    }
}
void solve(){
   // int n;
    cin>>n;
    vector<string> s(2);
    cin>>s[0]>>s[1];
    vector<vector< int >> edges(n*2,vector<int>());
    //second row = n+ col;
    vector<int> d = {0,0,1,-1};
    vector<int> p = {1,-1,0,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            array<int,2> tp = destination(0+d[j],i+p[j],s);
            if(tp!=array<int,2>({-1,-1})){
                edges[i].push_back(tp[0]*n+tp[1]);
            }
        }
        for(int j=0;j<4;j++){
            array<int,2> tp = destination(1+d[j],i+p[j],s);
            if(tp!=array<int,2>({-1,-1})){
                edges[n+i].push_back(tp[0]*n+tp[1]);
            }
        }
    }
    vector<bool> tp (2*n);
    dfs(tp,0,edges);
    if(tp[2*n-1]){
        cout<<"YES\n";
    }else cout<<"NO\n";




}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

