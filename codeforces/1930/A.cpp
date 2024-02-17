#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
void solve(){
    int n;
    cin>>n;
    n*=2;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=0;
    for(int i=n-2;i>=0;i-=2){
        ans+=a[i];
    }
    cout<<ans<<"\n";
}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
}
