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
using namespace std;
const int MOD=998244353;
#define int long long
void solve() {
    int n;
    cin>>n;
    int a[n];
    string ans="";
    for(int i=0;i<n;i++){
        cin>>a[i];
        ans+='B';
    }
    if(a[0]==a[n-1]){
        cout<<"NO\n";
        return;
    }
    int ma=1;
    int elem=a[0];
    int c=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            c++;
            if(c>ma){
                ma=c;
                elem=a[i];
            }

        }else{
            c=1;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==elem) {
            ans[i]='R';
            break;
        }
    }
    cout<<"YES\n";
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}