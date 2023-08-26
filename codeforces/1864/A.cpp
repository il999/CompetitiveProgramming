#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;

void solve(){

    int x,n,y;
    cin>>x>>y>>n;
    int a[n];
    a[0]=x;
    a[n-1]=y;
    for(int i=n-2;i>=0;i--){
        a[i]=a[i+1]-(n-1-i);
    }
    for(int i=0;i<n;i++){
        if(a[i]<x){
            cout<<"-1\n";
            return;
        }
    }
   // cout<<"ans\n";
    a[0]=x;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    

    

}
int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();

    }
}