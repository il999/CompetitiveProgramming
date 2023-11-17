#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
ll add(ll x, ll y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return x * 1ll * y % MOD;
}

ll binpow(ll x, ll y)
{
    ll z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

ll inv(ll x)
{
    return binpow(x, MOD - 2);
}

ll divide(ll x, ll y)
{
    return mul(x, inv(y));
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<array<int,2> > add;
    vector<array<int,2> > subtract;
    int l,r;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        array<int,2 > tp;
        tp[0]=l;
        tp[1]=r;
        add.push_back(tp);
        swap(tp[0],tp[1]);
        subtract.push_back(tp);
    }
   // build(1,0,n-1);
    sort(add.begin(),add.end());
    sort(subtract.begin(),subtract.end());
    int in1=0;
    int in2=0;
    int ans=0;
    int ones=0;
    int maxi=0;
    int tot=0;
    for(int i=0;i<n;i++){
        tot++;
        while(in1<n&&subtract[in1][0]<add[i][0]){
            tot--;
            if(subtract[in1][1]==1) ones--;
            in1++;
        }
        if(add[i][0]==1) ones++;
        if(add[i][1]==m) maxi++;
        ans=max(tot-min(ones,maxi),ans);
      //  cout<<ans<<" "<<ones<<" "<<maxi<<" "<<"\n";
    }
    cout<<ans<<"\n";

    // add all things that overlap with i ? never bad to do so if we take it as the max


}
int main()
{
    // cout<<"here\n";
    //  ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}