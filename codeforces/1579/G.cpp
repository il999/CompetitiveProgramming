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
using ll=long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a (n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int> > dp (n+1,vector<int>(2001,1e9));
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int x=0;x<=2000;x++){
            int ans=dp[i][x];
            if(a[i]>x) dp[i+1][0] = min(dp[i+1][0],(ans-x)+a[i]);
            if(a[i]<=x) dp[i+1][x-a[i]] = min(dp[i+1][x-a[i]],ans);
            if(x+a[i]<=2000){
                dp[i+1][x+a[i]]=min(dp[i+1][x+a[i]],max(x+a[i],ans));
            }
        }
    }
    int ans=1e9;
    for(int i=0;i<2001;i++){
        ans = min(ans,dp[n][i]);
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

