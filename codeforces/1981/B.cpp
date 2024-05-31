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
void solve() {
    int n,m;
    cin>>n>>m;
    int l = max(0ll,(n-m));
    int r = n+m;
    int ans=0;
    int sofarl=0;
    int sofarr=0;
    for(int i=0;i<32;i++){
        if(l&(1<<(i)))sofarl+=(1<<(i));
        if(r&(1<<(i))){
            sofarr+=(1<<(i));
            ans+=(1<<(i));
        }else if((l-sofarl)<(r-sofarr)){
            ans+=(1<<(i));
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}