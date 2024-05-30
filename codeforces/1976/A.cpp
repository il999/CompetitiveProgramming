
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

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int p=0;
    for(int i=0;i<n;i++) {
        if(s[i]-'0'<=9&&s[i]-'0'>=0) {
            if(i!=0&&(s[i]-'0'<s[i-1]-'0')) {
                cout<<"NO\n";
                return;
            }
            p=i+1;
        }else {
            break;
        }
    }
    for(int i=p;i<n;i++) {
        if(s[i]-'a'>=0&&s[i]-'a'<=25) {
            if(i==p) continue;
            if(s[i]-'a'<s[i-1]-'a') {
                cout<<"NO\n";
                return;
            }
        }else {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}
