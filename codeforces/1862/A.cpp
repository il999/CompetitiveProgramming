#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;

void solve(){
    int n,m;
    cin>>n>>m;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    string vi="vika";
    int in=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(s[j][i]==vi[in]){
                in++;
                break;
            }
            

        }
        if(in==4){
                cout<<"YES\n";
                return;
            }
        
    }
    cout<<"NO\n";
    
    

    

}
int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();

    }
}