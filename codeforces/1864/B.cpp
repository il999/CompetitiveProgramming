#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(k%2==1){
        string a="";
        string b="";
        for(int i=0;i<n;i++){
            if(i%2==0){
                a+=s[i];
            }else{
                b+=s[i];
            }
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        string fin="";
        for(int i=0;i<n;i++){
            if(i%2==0){
                fin+=a[i/2];
            }else{
                fin+=b[i/2];
            }
        }
        cout<<fin<<"\n";
    }else{
        string a="";
        string ne=s;
        sort(ne.begin(),ne.end());
        cout<<ne<<"\n";

    
    }
    
    
    

    

}
int main(){
    int t;
    cin>>t;
    // ios_base::sync_with_stdio(0); cin.tie(0);
    while(t--){
    solve();
    }
}