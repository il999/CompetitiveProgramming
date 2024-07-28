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
#include <chrono>
#include <numeric>
using namespace std;
const int MOD =1e9+7;
#define int long long
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
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v(n+1,vector<int>());
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    vector<bool> seen(n+1);
    vector<int> p(n+1);
    seen[1]=true;
    bool alice=false;
    while(!q.empty()){
        int u =q.front();
        q.pop();
        for(int to: v[u]){
            if(!seen[to]) {
                p[to] = p[u] + 1;
                seen[to] = true;
                q.push(to);
            }else{
                if(abs(p[u]-p[to])%2==0){
                    alice=true;
                    break;
                }
            }
        }
        if(alice) break;
    }
    vector<queue<int>  > table(3,queue<int>());
    for(int i=1;i<=n;i++){
        table[(p[i]%2)+1].push(i);
    }
    if(alice){
        cout<<"Alice\n";
        cout.flush();
        for(int i=0;i<n;i++){
            cout<<"1 2\n";
            cout.flush();
            cin>>a>>b;
            if(a==-1||b==-1) exit(0);
        }
    }else{
        cout<<"Bob\n";
        cout.flush();

        for(int i=0;i<n;i++){
            cin>>a>>b;
            if(a>b) swap(a,b);
            if(table[a].empty()&&b==3){
                if(a==1) b=2;
                else b=1;
                int tp =table[b].front();
                table[b].pop();
                cout<<tp<<" "<<3<<"\n";
                cout.flush();
                continue;
            }
            if(table[a].empty()) a=b;
            int tp = table[a].front();
            table[a].pop();
            cout<<tp<<" "<<a<<"\n";
            cout.flush();
        }
    }


}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();

}