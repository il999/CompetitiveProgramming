#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define int long long
using ll = long long;
void solve(){
   int n,p,l,t;
   cin>>n>>p>>l>>t;
    int low=0;
    int high=n;
    int possible=0;
    while(low<high){
        int mid=(low+high)/2;
        int days=n-mid;
        int tot=t*min(2*days,((n-1)/7+1));
        tot+=l*(days);
        if(tot>p){
            low=mid+1;
            possible = max(possible,mid);
        }else{
            high=mid;
        }
    }

    int days=n-possible-1;
    int tot=t*min(2*days,((n-1)/7+1));
    tot+=l*(days);
    if(tot>=p)possible++;
    cout<<possible<<"\n";
}
signed main() {
    int t;
    cin>>t;
    while(t--) solve();
}
