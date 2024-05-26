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
const int MOD=998244353;
#define int long long
void dfs(int u, vector<vector<int> >& v, vector<int>& dis,int from){
    for(int to:v[u]){
        if(to==from) continue;
        dis[to]=dis[u]+1;
        dfs(to,v,dis,u);
    }
}
int ans2=0;
int ma=0;
void dfs2(int u, vector<vector<int> >& v, vector<int>& toadd,int from,vector<int>& depth){
  //  cout<<u<<" u\n";
    if(v[u].size()==1&&from!=-1){
        toadd[u]=1;
        return;
    }
    int num =0;
    for(int to : v[u]){
        if(to == from) continue;
        dfs2(to,v,toadd,u,depth);
        depth[u]=max(depth[u],depth[to]+1);
        ma=max(toadd[to],ma);
        toadd[u]+=toadd[to];
        num++;
       // cout<<toadd[u]<<'\n';
    }
    if(from==-1||num>=2){
       // cout<<"here\n";
        ans2+=toadd[u]*2;
        toadd[u] = 1;
    }else{
        toadd[u]++;
    }
  //  cout<<u<<" "<<toadd[u]<<"\n";
}
void solve() {
    int n;
    cin>>n;
    int A,B;
    cin>>A>>B;
    vector<vector<int > > v (n,vector<int >());
    int x1,y1;
    A--;B--;
    for(int i=0;i<n-1;i++){
        cin>>x1>>y1;
        x1--;y1--;
        v[x1].push_back(y1);
        v[y1].push_back(x1);
    }
    vector<int> dis (n+1,0);
    vector<int> dis2 (n+1,0);
    dfs(A,v,dis,-1);
    dfs(B,v,dis2,-1);
    int add = (dis[B]%2);
    //if(add)
    ans2=0;
    ma=0;
    vector<int> toadd(n+1,0);
    vector<int> toadd2(n+1,0);
    vector<int> depth(n+1,0);
    vector<int> depth2(n+1,0);
    dfs2(A,v,toadd,-1,depth);
    int ansa = ans2;
    ans2=0;
    dfs2(B,v,toadd2,-1,depth2);


  //  cout<<add<<" "<<ans2<<" "<<ma<<" "<<dis[B]<<'\n';
     for(int i=0;i<n;i++){
         if(dis[i]<=dis[B]&&dis2[i]<=dis2[A]&&v[i].size()==1) add=0;
     }
     if(dis[B]==1) add=0;
    int realans= dis[B]+2*(n-1)-depth[A];
    int realans2= dis[B]+2*(n-1)-depth2[B]+(dis[B]%2);
   // cout<<realans<<" "<<realans2<<"\n";
  // cout<<add<<"\n";

    cout<<min(realans,realans2)<<"\n";




}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}