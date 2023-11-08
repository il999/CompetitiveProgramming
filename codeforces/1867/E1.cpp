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

int divide(int x, int y)
{
    return mul(x, inv(y));
}
void solve(){
    int n,k;
    cin>>n>>k;
    if(n%k==0){
        int x=0;
        int tp;
        for(int i=1;i<=n;i+=k){
            cout<<"? "<<i<<"\n";
            cout.flush();
            cin>>tp;
            x^=tp;
        }
        cout << "! " << x << "\n";
        cout.flush();
        return;
    }else {
        int x = 0;
        int p1;
        int p2;
        int tp;
        int last=1;
        for(int i=1;i<=n-k+1;i+=k) {
            cout << "? " << i << "\n";
            cout.flush();
            cin >> tp;
            x ^= tp;
            last=i+1;
        };
        for (int i = last; i <= n - k; i += 2) {
            cout << "? " << i << "\n";
            cout.flush();
            cin >> p1;
            cout << "? " << i + 1 << "\n";
            cout.flush();
            cin >> p2;
            x ^= (p1 ^ p2);

        }
        cout << "! " << x << "\n";
        cout.flush();

    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}