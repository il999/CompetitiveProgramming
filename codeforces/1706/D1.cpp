#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    vector<vector<int> > pre(n,vector<int>(a[n-1]+5));
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            pre[i][a[i]/j+1]++;
        }
        for(int j=1;j<=a[n-1]+4;j++){
            pre[i][j]+=pre[i][j-1];
        }
    }
    int ma=a[n-1];
    int ans=1e9;
    for(int i=1;i<=ma+1;i++){
        int low=i;
        int high=a[n-1]+2;
        while(low<high){
            int mid = (low+high)/2;
            bool work = true;
            for(int j=0;j<n;j++){
                if(pre[j][mid]-pre[j][i-1]==0) work=false;
            }
            if(!work){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        if(high != a[n-1]+2) {
           // cout << high << " " << i << "\n";
            ans = min(ans, high - i);
        }
    }
    cout<<ans<<"\n";
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
