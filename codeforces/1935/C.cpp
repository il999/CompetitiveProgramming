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
int add(int x, int y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y) {
    return mul(x, inv(y));
}
void solve(){
    ll l;
    int n;
    cin>>n>>l;
    vector<array<ll,2> > messages;
    ll a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        messages.push_back({b,a});
    }
    sort(messages.begin(),messages.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        ll sum=0;
        ll added=0;
        priority_queue<ll> pq;
        for(int j=i;j<n;j++){
            if(messages[j][0]-messages[i][0]>=l) break;
            pq.push(messages[j][1]);
            sum+=messages[j][1];
            added++;
            while(sum>(l-(messages[j][0]-messages[i][0]))){

                sum-=pq.top();
                pq.pop();
                added--;
               // cout<<"hello\n";
            }
            ans=max(ans,added);
        }


    }
    cout<<ans<<"\n";

}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
