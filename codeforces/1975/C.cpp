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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        bool work=0;
        if((i>0)&&a[i-1]>=a[i]) work=1;
        if((i<n-1)&&a[i+1]>=a[i]) work=1;
        if((i>1)&&a[i-2]>=a[i]) work=1;
        if((i<n-2)&&a[i+2]>=a[i]) work=1;
        if(work) ans=max(ans,a[i]);
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