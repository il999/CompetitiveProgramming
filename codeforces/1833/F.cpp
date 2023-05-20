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
    int m;
    cin>>m;
    map<int,int> ma;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(ma.find(a[i])==ma.end())ma[a[i]]=1;
        else ma[a[i]]++;
    }
    vector<array<int,2> > v;
    array<int,2> tp;
    for( auto it : ma){
        tp[0]=it.first;
        tp[1]=it.second;
        v.push_back(tp);
    }
    int ans=0;
    if(v.size()<m){
        cout<<"0\n";
        return;
    }
   // cout<<v.size()<<"\n";
    for(int i=0;i<(v.size()-m+1);i++){
       // cout<<"here\n";
        int tp=1;
        if(v[i+m-1][0]-v[i][0]+1==m){
           // cout<<"grrr";
            for(int j=0;j<m;j++){
                tp=mul(tp,v[i+j][1]);
            }
           // cout<<tp<<" ooga\n";
            ans=add(ans,tp);
           // cout<<ans<<" ooga\n";
            int last=i;
            int cur=i+m;
            while(cur<v.size()&&v[cur][0]==v[cur-1][0]+1){
                
                tp=divide(tp,v[last][1]);
                tp=mul(tp,v[cur][1]);
                ans=add(ans,tp);
                //cout<<ans<<" answer\n";
                cur++;
                last++;
            }
            i=cur-1;
        }
    }
    cout<<ans<<"\n";
    
    
    


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}