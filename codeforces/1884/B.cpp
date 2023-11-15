#include <iostream>
#include <vector>
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
    int n;
    cin>>n;
    string s;
    cin>>s;
  //  int comeintoaffect=0;
    vector<ll> ones(n+1);
    ones[n]=0;
    ll zeros=0;
    for(int i=n-1;i>=0;i--){
        ones[i]=ones[i+1];
        if(s[i]=='1'){
            ones[i]++;
        }
        else zeros++;
    }
   // vector<int> space(n+1)
    
    vector<ll> pre(n+1);
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            pre[i+ones[i+1]]++;
        }
    }
    ll tp=0;
    for(int i=n-1;i>=0;i--){
        if(ones[0]>i){
            cout<<"-1 ";
            continue ;
        }
        tp+=pre[i];

        pre[i]+=pre[i+1];
        cout<<pre[i]<<" ";
        pre[i]+=tp;
    }
    cout<<"\n";

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