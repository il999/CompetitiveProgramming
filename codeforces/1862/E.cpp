#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;

void solve(){
    ll n,m,d;
    cin>>n>>m>>d;
    ll value[n];
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    ll dp[n];
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    ll si=0;
    ll total=0;
    ll lasttaken=0;
    for(int i=0;i<n;i++){
        if(si<m&&value[i]>0){
            pq.push(value[i]);
            total+=value[i];
            lasttaken=i+1;
            si++;
        }
        else if(si>=m && value[i]>pq.top()){
            total+=value[i]-pq.top();
            pq.pop();
            pq.push(value[i]);
            lasttaken=i+1;
        }
        
        dp[i]=total-d*(i+1);
       // cout<<dp[i]<<" ";
    }
   // cout<<"\n";
    ll best=0;
    for(int i=0;i<n;i++){
        best=max(dp[i],best);
    }
    cout<<best<<"\n";

    
    

    

}
int main(){
    int t;
    cin>>t;
    // ios_base::sync_with_stdio(0); cin.tie(0);
    while(t--){
    solve();
    }
}