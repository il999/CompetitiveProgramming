#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
vector<vector<int> > fen(30001, vector<int>());

void solve(){
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int dp[n+1][n+2];
    bool opdone[n+1][n+2];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n+1;j++){
                dp[i][j]=0;
                opdone[i][j]=0;
            }
        }
    int op=0;
    vector<int> diagonals(n*4);
    vector<int> otherdiag(n*6);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            dp[i][j]+=diagonals[i+j];
            dp[i][j]+=otherdiag[i+n-j];
            int add=1;
            if(s[i-1][j-1]=='0') add=0;
            if((dp[i][j]+add)%2==1){
                op++;
                diagonals[i+j]++;
                otherdiag[i+n-j]++;
                dp[i][j]++;
            }

        }
        

    }
    cout<<op<<"\n";
    
    

}
int main(){
     ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    solve();
    }
}