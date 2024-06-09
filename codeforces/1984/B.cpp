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
    string s;
    cin>>s;
    int n= s.size();
    for(int i=0;i<n-1;i++){
        if(s[i]=='0'){
            cout<<"NO\n";
            return;
        }
    }
    if(s[n-1]=='9'){
        cout<<"NO\n";
        return;
    }
    if(s[0]!='1'){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}