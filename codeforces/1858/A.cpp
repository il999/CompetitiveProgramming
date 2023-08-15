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
    int a,b,c;
    cin>>a>>b>>c;

    if(c%2==0){
        if(a<=b){
            cout<<"Second\n";
        }else{
            cout<<"First\n";
        }
    }else{
        if(a<b){
            cout<<"Second\n";
        }else cout<<"First\n";
    }
}
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      int t;
      cin>>t;
      while(t--)
        solve();
}