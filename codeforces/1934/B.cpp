#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> precomp(1e5,1e9);
void solve(){
    ll n;
    cin>>n;
    // 30 made with basically we wanna get to it 0 mod 15;
    //fastest way to get to 0 mod 15;
    // then just spam 15;
    // 3tens = 2*15
    // 2 threes = 6;
    if(n<1e5){
        cout<<precomp[n]<<endl;
    }else{
        for(int j=1;j<=16;j++){
            if((100000*1ll-j)%15==(n%15)){
                cout<<precomp[100000-j]+(n-(100000-j))/15<<endl;
                return;
            }
        }
    }



}
int main() {
    int t;
    cin>>t;
    vector<int> coins = {1,3,6,10,15};
    precomp[0]=0;
    for(int i=0;i<1e5;i++) {
        for(int j=0;j<5;j++){
            if(coins[j]>i) continue;
            precomp[i]=min(1+precomp[i-coins[j]],precomp[i]);
        }
    }
    while(t--){
        solve();
    }
}
