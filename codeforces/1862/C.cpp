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
    vector<int> gers(n+1,0);
    for(int i=0;i<n;i++){
        if(a[i]>=n){
            gers[n]++;
        }
        else{
            gers[a[i]]++;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        gers[i]+=gers[i+1];
    }

    vector<int> ne;
    for(int i=n-1;i>=0;i--){
        ne.push_back(gers[n-i] );
    }
    for(int i=0;i<n;i++){
        if(ne[i]!=a[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    

    

}
int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    solve();
    }
}