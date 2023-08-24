#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;

void solve(){
    ll n;
    cin>>n;
    ll low=1;
    ll high=3*(1e9);
    while(low<high){
        ll mid=(low+high)/2;
        if((mid*(mid-1))/2>=n){
            //cout<<mid<<"\n";
            high=mid;
        }else{
            low=mid+1;
        }
    }
    while((low*(low-1))/2>n){
        low-=1;
    }
   // cout<<high<<" "<<2*n-(high*(high-1)/2)<<"\n";
    low+=(n-(low*(low-1))/2);
    cout<<low<<"\n";
    
    

    

}
int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();

    }
}