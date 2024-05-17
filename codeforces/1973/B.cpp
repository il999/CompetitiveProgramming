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
const int MOD=998244353;
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
int GCD(int a, int b){
    if(a<b) swap(a,b);
    if(a%b==0) return b;
    return GCD(b,a%b);
}
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int orn=0;
    for(int i=0;i<n;i++){
        orn|=a[i];
    }
    vector<bool> bitn (21);
    //cout<<orn<<" "<<1<<2<<"\n";
    for(int i=0;i<=20;i++){
        if((orn&(1<<i))!=0){
            bitn[i]=true;
        }
        //cout<<bitn[i]<<" ";
    }
    int madis=0;
    int low =1;
    int high=n;
    while(low<high){
        vector<int> currentbit (21);
        int mid=(low+high)/2;
        for(int i=0;i<mid;i++){
            for(int j=0;j<=20;j++){
                if((a[i]&(1<<(j)))!=0){
                    currentbit[j]++;
                }
            }
        }
        bool broke=0;
        for(int j =0 ;j<21;j++){
           // cout<<currentbit[j]<<" ";
            if(bitn[j]&&currentbit[j]==0){
                low=mid+1;
                broke=1;
            }
        }
        if(broke) continue;
        for(int i=mid;i<n;i++){
            for(int j=0;j<=20;j++){
                if((a[i-mid]&(1<<(j)))!=0){
                    currentbit[j]--;
                }
            }for(int j=0;j<=20;j++){
                if((a[i]&(1<<(j)))!=0){
                    currentbit[j]++;
                }
            }
            for(int j=0;j<=20;j++){
                if(bitn[j]&&currentbit[j]==0){
                    low=mid+1;
                    broke=1;
                }
            }
            if(broke){
                break;
            }
        }
        if(broke) continue;
        high=mid;
    }
    cout<<low<<'\n';



}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}