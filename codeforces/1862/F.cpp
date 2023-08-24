#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;

void solve(){
    ll w,f;
    cin>>w>>f;
    ll n;
    cin>>n;
    ll a[n];
    ll limit=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        limit+=a[i];
    }
    ll low=(limit/(w+f));
    ll high=1e6+1;
    vector<vector<bool> > dp(n+1,vector<bool>(limit+1));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
            for(int j=0;j<=limit;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=a[i]&&dp[i-1][j-a[i]]){
                    dp[i][j]=dp[i-1][j-a[i]];
                    
                }
              //  if(dp[i][j]&&j<=fcur)ma1=max(ma1,j);
              //  if(dp[i][j]&&j<=wcur)ma2=max(ma2,j);
            }
        }
    while(low<high){
        ll mid=(low+high)/2;
        ll fcur=f*mid;
        ll wcur=w*mid;
        ll ma1=0;
        ll ma2=0;
        
        bool work=0;
        //cout<<ma1<<" "<<ma2<<"\n";
        for(ll i=0;i<=limit;i++)
        {
            if(dp[n][i]&&i<=fcur)ma1=max(ma1,i);
            if(dp[n][i]&&i<=wcur)ma2=max(ma2,i);
        }
            //now we do wcur for limit-1-ma1;
            if(wcur>=limit-ma1){
            
                work=1;
            }
            if(fcur>=limit-ma2){
                work=1;
            }
            if(work){
                high=mid;
            }else{
                low=mid+1;
            }

        
        
    }
    cout<<high<<"\n";
    

    

}
int main(){
     ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    solve();
    }
}