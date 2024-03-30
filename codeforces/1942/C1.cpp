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
void solve() {
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> v;
    int a;
    for(int i=0;i<x;i++) {
        cin>>a;
        v.push_back(a);
    }
    int ans=0;
    sort(v.begin(),v.end());
    for(int i=1;i<x;i++){
        if(v[i]-v[i-1]==2){
            ans++;
        }
    }
    if(v[x-1]==n-1&&v[0]==1){
        ans++;
    }
    if(v[x-1]==n&&v[0]==2){
        ans++;
    }
    int oldans=0;

    bool start=1;
    //cout<<ans<<'\n';
    while(ans!=oldans||start){
        oldans=ans;
        start=0;
        vector<int> tp;
        for(int i=0;i<v.size();i++){
            tp.push_back(v[i]);
        }
        if(tp.size()==2) break;
        v.clear();
        for(int i=0;i<tp.size();i++){
            if(i==tp.size()-1){
                v.push_back(tp[i]);
                break;
            }
            v.push_back(tp[i]);
          //  cout<<"add\n";
            ans++;
            i++;
        }

       // cout<<v.size()<<" hola\n";

    }
    cout<<ans<<"\n";


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

