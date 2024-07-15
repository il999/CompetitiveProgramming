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
#include <chrono>
#include <numeric>
using namespace std;
const int MOD =998244353;
#define int long long
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
void solve() {
    int n;
    cin>>n;
    vector<int> binary;
    int tp=n;
    int one=0;
    int two=0;
    vector<int> ans;
    int c=0;
    int thing=0;
    vector<int> toadd;
    while(tp>0){
        if(tp%2==1){
            toadd.push_back(((1ll)<<(thing)));
            if(c%2==0) one+=((1ll)<<(thing));
            else two+=((1ll)<<thing);
            c++;
        }
        thing++;
        tp/=2;
    }
    if(one>two) swap(one,two);
    if(one==0){
        cout<<"1\n";
        cout<<two<<"\n";
        return;
    }

    for(int i=toadd.size()-1;i>=0;i--){
        ans.push_back(one);
        one+=toadd[i];
        swap(one,two);
    }
    cout<<ans.size()+1<<"\n";
    for(int x: ans){
        cout<<x<<" ";
    }
    cout<<n<<"";
    cout<<"\n";



}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
     cin>>t;
    while(t--)
        solve();

}