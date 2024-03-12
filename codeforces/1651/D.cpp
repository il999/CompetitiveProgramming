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

bool distance_of_one(int i,int x,int y,map<array<int,2>,int>& m,vector<array<int,2> >& ans){
    if(m.find({x,y+1})==m.end()){
        ans[i] = {x,y+1};
        return true;
    }
    if(m.find({x,y-1})==m.end()){
        ans[i] = {x,y-1};
        return true;
    }
    if(m.find({x-1,y})==m.end()){
        ans[i] = {x-1,y};
        return true;
    }
    if(m.find({x+1,y})==m.end()){
        ans[i] = {x+1,y};
        return true;
    }
    return false;
}
void add_to_queue(int x, int y, int x2,int y2,queue<array<int,2> >& q, map<array<int,2>,int>& m,map<array<int,2>,int>& m2,vector<array<int,2> >& ans){
    if(m.find({x2,y2})!=m.end()&&m[{x2,y2}]==1e9){
        q.push({x2,y2});
        m[{x2,y2}]=m[{x,y}]+1;
        ans[m2[{x2,y2}]]=ans[m2[{x,y}]];
    }
}
array<int,2> INF ={1000000000,1000000000};
void solve(){
    int n;
    cin>>n;
    vector<array<int,2> > points(n,array<int,2>());
    map<array<int,2>,int> m;
    vector<array<int,2> > ans(n,array<int,2>());
    map<array<int,2>,int> m2;
    for(int i=0;i<n;i++) {
        cin >> points[i][0] >> points[i][1];
        m2[points[i]]=i;
        m[points[i]]=1e9;
    }
    queue<array<int,2> > q;
    for(int i=0;i<n;i++){
        if(distance_of_one(i,points[i][0],points[i][1],m,ans)){
            q.push({points[i][0],points[i][1]});
            m[points[i]]=1;
        }
    }
    while(!q.empty()){
        array<int,2> cur_point = q.front();
        q.pop();
        add_to_queue(cur_point[0],cur_point[1],cur_point[0]+1,cur_point[1],q,m,m2,ans);
        add_to_queue(cur_point[0],cur_point[1],cur_point[0]-1,cur_point[1],q,m,m2,ans);
        add_to_queue(cur_point[0],cur_point[1],cur_point[0],cur_point[1]+1,q,m,m2,ans);
        add_to_queue(cur_point[0],cur_point[1],cur_point[0],cur_point[1]-1,q,m,m2,ans);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    }
    //cout<<"\n";

}
int main(){
    int t=1;
    while(t--) solve();
}

