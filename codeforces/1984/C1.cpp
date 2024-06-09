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
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    vector<array<int,2> > ma(n+1,array<int,2>());
    ma[0]={0,0};
    for(int i =1;i<=n;i++){
        ma[i][0] = max({a[i-1]+ma[i-1][0],abs(a[i-1]+ma[i-1][1]),abs(a[i-1]+ma[i-1][0])});
        ma[i][1] = ma[i-1][1]+a[i-1];
    }
    cout<<ma[n][0]<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}