
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
#define int long long
using namespace std;

void solve() {
    int n;
    cin>>n;
    int a[n];
    int b[n+1];
    for(int i =0;i<n;i++) cin>>a[i];
    for(int i=0;i<=n;i++) cin>>b[i];
    int mi=1e9+7;
    int in=-1;
    for(int i=0;i<n;i++){
        if(abs(a[i]-b[n])<mi){
            mi=abs(a[i]-b[n]);
            in=i;
        }
        if(abs(b[i]-b[n])<mi){
            mi=abs(b[i]-b[n]);
            in=i;
        }
        if(max(a[i],b[i])>=b[n]&&min(b[i],a[i])<=b[n]){
            mi=0;
            in=i;
        }
    }
    //cout<<mi<<"\n";

    long long ans=mi+1;
    for(int i=0;i<n;i++){
        ans+= abs(a[i]-b[i]);
    }
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}
