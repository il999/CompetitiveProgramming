#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
void solve(){
    int n;
    cin>>n;
    for(int i=1; i<=n/2;i++){
        cout<<i<<" "<<n-(i-1)<<" ";
    }
    if(n%2==1){
        cout<<(n+1)/2;
    }
    cout<<"\n";

}
int main() {
    int t;
    cin>>t;
    while(t--) solve();
}
