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
    int n,m;
    cin>>n>>m;
    int a[n+m+1];
    int b[n+m+1];
    for(int i=0;i<n+m+1;i++){
        cin>>a[i];
    }
    for(int i=0;i<n+m+1;i++) cin>>b[i];
    int ans=0;
    int ntemp=0;
    int mtemp=0;
    vector<int> isN(n+m+1);
    vector<int> firstnshafted(n+m+2,1e9);
    vector<int> firstmshafted(n+m+2,1e9);
    for(int i=0;i<n+m;i++){
        if((ntemp!=n&&a[i]>b[i])||mtemp==m){
            ntemp++;
            ans+=a[i];
            if(mtemp==m&&b[i]>a[i]) firstmshafted[i]=i;
            isN[i]=1;
        }else if((mtemp!=m&&a[i]<b[i])||ntemp==n){
            mtemp++;
            ans+=b[i];
            if(ntemp==n&&a[i]>b[i]) firstnshafted[i]=i;
        }
    }
    for(int i=n+m;i>=0;i--){
        firstmshafted[i]=min(firstmshafted[i],firstmshafted[i+1]);
        firstnshafted[i]=min(firstnshafted[i],firstnshafted[i+1]);
    }
    vector<int> toprint(n+m+1);
    toprint[n+m]=ans;
    for(int i=n+m-1;i>=0;i--){
        int tpans=ans;
        if(isN[i]){
            if(firstnshafted[i+1]!=1e9) {
                tpans =toprint[firstnshafted[i+1]]+a[firstnshafted[i+1]]-a[i];
            }else{
                tpans=toprint[n+m]-a[i]+a[n+m];
            }
        }else{
            if(firstmshafted[i+1]!=1e9) {
                tpans =toprint[firstmshafted[i+1]]+b[firstmshafted[i+1]]-b[i];
            }else{
                tpans=toprint[n+m]-b[i]+b[n+m];
            }
        }
        toprint[i]=tpans;
    }
    for(int pr : toprint){
        cout<<pr<<" ";
    }
    cout<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}