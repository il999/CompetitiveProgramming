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
vector<array<int,2> > wanted(200001,array<int,2>());
//array<int,2> tp;
struct segtree{
    int n;
    vector<array<int,2> > seg;
    segtree(int n) : n(n), seg(n*4,array<int,2>() ) {}
    void build(int v,int tl,int tr){
        if(tl==tr){
            array<int,2> tpppp=wanted[tl];
           // cout<<wanted[tl][0]<<"hhooo\n";
            seg[v]=tpppp;
            return;
        }
        int tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        if(seg[v*2][0]<seg[v*2+1][0]){
            seg[v]=seg[v*2];
        }else{
            seg[v]=seg[v*2+1];
        }
        //seg[v]=min(seg[v*2],seg[v*2+1]);
      //  cout<<seg[v][0]<<" "<<seg[v][1]<<"\n";

    }
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            seg[v][0] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            if(seg[v*2][0]<seg[v*2+1][0]){
                seg[v]=seg[v*2];
            }else{
                seg[v]=seg[v*2+1];
            }
        }
    }
    array<int,2> query(int v,int tl, int tr, int l, int r){
        if(l>r){
            array<int,2> inf;
            inf[0]=1e9+7;
            inf[1]=-1;
            return inf;
        }
        //array<int,2> tp;
        if(l==tl&&r==tr){
            return seg[v];
        }
        int tm=(tl+tr)/2;
      //  cout<<seg[v][0]<<" "<<seg[v][1]<<"\n";
        
         return min(query(v*2,tl,tm,l,min(tm,r)),query(v*2+1,tm+1,tr,max(tm+1,l),r));
        
    }
};
void solve(){
    int n;
    cin>>n;
    int w[n];
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
        cin>>w[i];
    }
   // for(int i=0;i<n;i++) cin>>w[i];
    vector<array<int,3> > both;
    vector<array<int,3> > both2;
    array<int,3> tp;
    for(int i=0;i<n;i++){
        tp[0]=w[i];
        tp[1]=h[i];
        tp[2]=i;
        
        both.push_back(tp);
        tp[0]=h[i];
        tp[1]=w[i];
        both2.push_back(tp);
    }
    //wanted.clear();
    sort(both.begin(),both.end());
    sort(both2.begin(),both2.end());
    array<int,2> wt;
    //vector<array<int,2> > wanted(n,array<int,2>());
    for(int i=0;i<n;i++){
        wt[0]=both[i][1];
        wt[1]=both[i][2];
        wanted[i]=(wt);
    }
   // vector<int> ans(n,-1);
   segtree one(n);
    one.build(1,0,n-1);
   // wanted.clear();
   
    for(int i=0;i<n;i++){
        wt[0]=both2[i][1];
        wt[1]=both2[i][2];
        wanted[i]=(wt);
    }
    segtree two(n);
    two.build(1,0,n-1);
   // array<int,2> answer=one.query(1,0,n-1,0,n-1);
    // cout<<answer[1]<<"ooga ogga\n";
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        //now so the things are sorted by their w
        //we need to find the inded where w is less than current h;
        int x=both[i][1];
        int low=0; int high=n; int mid; int works=-1;
        while(low<high){
            mid=(low+high)/2;
            if(both[mid][0]<x){
                low=mid+1;
                works=mid;
            }else{
                high=mid;
            }
        }
       
        if(works>=0){
            //cout<<works<<"\n";
            one.update(1,0,n-1,i,1e9+7);
            
            array<int,2> temp=one.query(1,0,n-1,0,works);
            if(temp[0]!=1e9+7&&temp[0]<both[i][0]){
                ans[both[i][2]]=temp[1]+1;
            }
            one.update(1,0,n-1,i,both[i][1]);
        }
    }
   
    int lastdiff=-1;
    for(int i=1;i<n;i++){
        if(both2[i][0]!=both2[i-1][0]){
            lastdiff=i-1;
        }
        if(lastdiff==-1) continue;
        array<int,2> temp;
        temp=two.query(1,0,n-1,0,lastdiff);
        if(temp[0]<both2[i][1]){
            ans[both2[i][2]]=temp[1]+1;
            //cout<<lastdiff<<" "<<temp[0]<<"heheh\n";
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
   

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}