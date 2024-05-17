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
    int p[n];
    for(int i=0;i<n;i++) cin>>p[i];
    vector<int> ans(n);
    vector<int> ans2(n);
    int place1=0;
    for(int i=0;i<n;i++){
        ans[i]=n+1-p[i];
        ans2[i]=ans[i];
        if(ans[i]==1) place1=i;
    }
    priority_queue<array<int,2> , vector<array<int,2> >> pq;
    priority_queue<array<int,2> , vector<array<int,2> > > pq2;
    for(int i=0;i<n;i+=2){
        pq.push({ans[i],i});
    }
    for(int i=1;i<n;i+=2) pq2.push({ans[i],i});
    pq2.push({ans[0],0});
    pq.push({ans[n-1],n-1});
    vector<array<int,2> > tocheck;
    vector<array<int,2> > tocheck2;
    for(int i=2;i<n-1;i+=2){
        tocheck2.push_back({ans[i],i});
    }
    for(int i=1;i<n-1;i+=2){
        tocheck.push_back({ans[i],i});
    }
    sort(tocheck.begin(),tocheck.end());
    sort(tocheck2.begin(),tocheck2.end());
    for(int i=tocheck.size()-1;i>=0;i--){
        if(pq.top()[0]<tocheck[i][0]) {
            pq.push(tocheck[i]);
            continue;
        }
        int place= pq.top()[1];
        pq.pop();
        pq.push({tocheck[i][0],place});
        swap(ans[tocheck[i][1]],ans[place]);
    }
    for(int i=tocheck2.size()-1;i>=0;i--){
        if(pq2.top()[0]<tocheck2[i][0]) {
            pq2.push(tocheck2[i]);
            continue;
        }
        int place= pq2.top()[1];
        pq2.pop();
        pq2.push({tocheck2[i][0],place});
        swap(ans2[tocheck2[i][1]],ans2[place]);
    }
    int first=0;
    int second=0;
    int a1[n];
    int a2[n];
    for(int i=0;i<n;i++){
        a1[i]=p[i]+ans[i];
        a2[i]=p[i]+ans2[i];
    }
    for(int i=1;i<n-1;i++){
        if(a1[i]>a1[i-1]&&a1[i]>a1[i+1])first++;
        if(a2[i]>a2[i-1]&&a2[i]>a2[i+1])second++;
    }
    if(first>second){
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }else{
        for(int i=0;i<n;i++) cout<<ans2[i]<<" ";
        cout<<"\n";
    }






}

signed main(){;
    int t;
    cin>>t;
    while(t--)
        solve();
   // while(t--) solve();
}