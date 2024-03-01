#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int long long;
vector<ll> precomp(1e5+1,1e9);

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
        for(ll j=1;j<=16;j++){
            if((100000*1ll-j)%15==(n%15)){
                cout<<precomp[100000*1ll-j]+(n-(100000*1ll-j))/15<<"\n";
                return;
            }
        }
    }



}
int main() {
    int t;
    cin>>t;
    vector<ll> coins = {1,3,6,10,15};
    precomp[0]=0;
    for(ll i=0;i<=1e5;i++) {
        for(ll j=0;j<5;j++){
            if(coins[j]>i) continue;
            precomp[i]=min(1ll+precomp[i-coins[j]],precomp[i]);
        }
    }
    while(t--){
        solve();
    }
}
