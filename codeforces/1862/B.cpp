#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(i==0) ans.push_back(a[0]);
        else{
            if(a[i]<a[i-1]){
                ans.push_back(1);
            }
                ans.push_back(a[i]);
            
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

    
    

    

}
int main(){
    int t;
    cin>>t;
    // ios_base::sync_with_stdio(0); cin.tie(0);
    while(t--){
    solve();
    }
}