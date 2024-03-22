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
int c=0;
void dfs(vector<int>& subtree, vector<int>& dfstree, vector<vector<int> >& v,int u,int last,int mid){
   // dfstree.push_back(u);
    for(int i=0;i<v[u].size();i++){
        if(v[u][i]!=last){
            dfs(subtree,dfstree,v,v[u][i],u,mid);
            subtree[u]+=max(0,subtree[v[u][i]]);
            if(subtree[u]>=mid){
                c++;
                //cout<<u<<" u\n";
                subtree[u]=-1e9;
            }

        }
    }

}
void solve() {
    int n,k;
    cin>>n>>k;
    vector<vector<int> > v(n,vector<int>());

    vector<int> dfstree;
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int low=0;
    int high=n+1;
    int possible=1;
    while(low<high){
        int mid=(low+high)/2;
        c=0;
        vector<int> subtree(n,1);
        dfs(subtree,dfstree,v,0,-1,mid);
       // if(subtree[0]>=mid)c++;

        if(c>k){
            possible=mid;
            low=mid+1;
        }else{
            high=mid;
        }

    }
    cout<<possible<<"\n";




}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

