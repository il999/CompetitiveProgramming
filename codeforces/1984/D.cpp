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
using namespace std;
const int MOD = vector<int>({998244353,998244521,998244679,1000000009,998244889})[rand()%5];
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
void compute_hash(string const& s,vector<int>& hashes,vector<int>& powers_of_p) {
    const int p = vector<int>({31,37,41,43,47})[rand()%5];
    const int m = MOD;
    long long hash_value = 0;
    long long p_pow = 1;
    powers_of_p.push_back(1);
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        hashes.push_back(hash_value);
        p_pow = (p_pow * p) % m;
        powers_of_p.push_back(p_pow);

    }
}
void solve() {

    int n;
    string s;
    cin>>s;
    n=s.size();
    vector<int> hashes;
    vector<int> powers_of_p;
    compute_hash(s,hashes,powers_of_p);
    int start=0;
    int end=0;
    for(int i=0;i<n;i++){
        if(s[i]!='a') break;
        start++;
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]!='a') break;
        end++;
    }
    if(start==n){
        cout<<n-1<<"\n";
        return;
    }
    vector<int> nextnona(n+1,-1);
    for(int i=n-1;i>=0;i--){
        if(s[i]!='a')nextnona[i]=i;
        else nextnona[i]=nextnona[i+1];
    }
    vector<int> numofways2(n*2+4);
    vector<int> numofways(n*2+4);
    for(int i=start;i>=0;i--){
        numofways2[i]++;
        numofways2[i+end+1]--;
    }
    for(int i=1;i<=n;i++){
        numofways2[i]=numofways2[i-1]+numofways2[i];
    }
    numofways[0]=numofways2[0];
    for(int i=1;i<=n;i++){
        numofways[i]=numofways2[i]+numofways[i-1];
    }
    int ans=0;
    for(int i=start;i<n;i++){
        if(s[i]=='a') continue;
        int hash1;
        if(start!=0) {
            hash1 = divide(add(hashes[i], -hashes[start - 1]), powers_of_p[start]);
        }else{
            hash1 = divide(hashes[i], powers_of_p[start]);
        }
        int minmiddle=1e9;
        int j= i +1;
        bool work=true;
        while(nextnona[j]!=-1){
        //   cout<<j<<" j \n";
            minmiddle= min(minmiddle,nextnona[j]-j);
            j=nextnona[j];
            if(j+(i-start)>=n){
                work=false;
                break;
            }
            int nexthash = divide(add(hashes[j+i-start],-hashes[j-1]),powers_of_p[j]);
            if(hash1!=nexthash){
                //cout<<hash1<<" "<<nexthash<<" "<<hashes[j+i-start]<<"\n";
               // cout<<i<<" "<<j<<"\n";
                work=false;
                break;
            }
            j+=(i-start+1);
        }
        if(work){
            if(minmiddle==1e9){
                ans+=(start+1)*(end+1);
            }
            else ans+=numofways[minmiddle];
           // cout<<minmiddle<<"\n";
        }
        if(minmiddle==1e9) break;
    }

    cout<<ans<<"\n";



}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) solve();
}