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
using ll=long long;

void solve(){
   // int n;
    string s;
    cin>>s;
    int n = s.size();
    vector<vector<bool> > starting(n,vector<bool>(n));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j]||s[i]=='?'||s[j]=='?'){
                starting[i][j-i]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<n;i++){
        int c=0;
        for(int j=0;j<n;j++){
            if(starting[j][i]){
                c++;
            }else{
                c=0;
            }
            if(c==i){
                ans=i;
            }
        }
    }
    cout<<ans*2<<"\n";




}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

