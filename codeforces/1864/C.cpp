#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;

void solve(){
    ll n;
    cin>>n;
    ll before=n;
    vector<ll> ans;
    ll two=1;
    ans.push_back(0);
    while(n>1){
        
        if(n%2==1){
            ans.push_back(two);
        }
        two*=2;
        n/=2;
    }
    //ans.pop_back();
    two/=2;
    while(two>=1){
        ans.push_back(two);
        two/=2;
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        before-=ans[i];
        cout<<before<<" ";
    }
    cout<<"\n";
    

}
int main(){
     ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    solve();
    }
}