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
int erekle(vector<int>& a, int n){
    long long sum = 0;

    auto move = [&]() {
        map<int, int> f;
        int MAD = 0;
        for (int i = 0; i < n; ++i) {
            ++f[a[i]];
            if (f[a[i]] == 2 && a[i] > MAD) MAD = a[i];
            sum += a[i];
            a[i] = MAD;
        }
    };

    move();
    // now a is in increasing order
    move();
    // now every block in a except possibly the last is at least two wide

    for (int i = 0; i < n; ++i) {
        sum += (long long)a[i] * (n-i);
    }
    return sum;
}
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int tot=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        tot+=a[i];
    }
    int MAD=0;
    int last=-1;
    map<int,int> already;
    vector<int> ar;
    for(int i=0;i<n;i++) {
        if (a[i]>MAD&&already[a[i]]==1) MAD = a[i];
        ar.push_back(MAD);
        ++already[a[i]];
    }
    map<int,int> next;
    MAD=0;
    for(int i=0;i<n;i++){
        if(ar[i]>MAD&&next[ar[i]]==1) MAD=ar[i];
        tot+=ar[i];
        ++next[ar[i]];
        ar[i]=MAD;
    }
    for(int i=0;i<n;i++){
        tot+=(long long)(n-i)*ar[i];
    }
    int num= erekle(a,n);

    cout<<tot<<"\n";


}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();

}