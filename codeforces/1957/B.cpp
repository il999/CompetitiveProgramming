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
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a;
    if(n==1){
        cout<<k<<'\n';
        return;
    }
    vector<int> binary;
    int k2=k;
    int n2=n;
    while(k>0){
        binary.push_back(k%2);
        k/=2;
    }

    int num2 = ((1<<(binary.size()-1)))-1;
    int num3 =(k2-num2);

    cout<<num2<<" "<<num3<<" ";
    for(int i=0;i<n2-2;i++){
        cout<<"0 ";
    }
    cout<<"\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}

