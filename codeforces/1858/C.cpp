#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
#include <stack>
using namespace std;
using ll=long long;
const int MOD=1e9+7;

void solve(){
    int n;
    cin>>n;
    vector<bool> inar(n+1,0);
    vector<int> ar;
    for(int i=1;i<=n;i++){
        if(inar[i]) continue;
        int in=i;
        ar.push_back(i);
        
        while(in*2<=n){
            in*=2;
            inar[in]=1;
            ar.push_back(in);
        }
    }
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<"\n";
}
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      int t;
      cin>>t;
      while(t--)
        solve();
}