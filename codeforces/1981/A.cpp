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
    int a,b;
    cin>>a>>b;
    int s=1;
    int c=0;
    while(s*2<=b){
        s*=2;
        c++;
    }
    cout<<c<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}