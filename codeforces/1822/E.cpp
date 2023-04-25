#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
#include <array>
using namespace std;
using ll=long long;
const int MOD=998244353;
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
   
   // int n;
   int n;
   cin>>n;
   string s;
   cin>>s;
   if(n%2==1){
    cout<<"-1\n";
    return;
   }
   vector<int> alpha(26,0);
   for (int i=0;i<n;i++){
    alpha[s[i]-'a']++;
   }
   for(int i=0;i<26;i++){
    if(alpha[i]>(n/2)){
        cout<<-1<<"\n";
        return;
    }
   }
   vector<int> alpha2(26,0);
   //vector<int> 
   int total=0;

   for(int i=0;i<n;i++){
    if(s[i]==s[n-i-1]){
        total++;
        alpha2[s[i]-'a']++;
    }
   }
   for(int i=0;i<26;i++) alpha2[i]/=2;
   bool working=1;
   int ans=0;
   while(working){
    sort(alpha2.rbegin(),alpha2.rend());
    if(alpha2[2]>0){
        alpha2[0]-=(alpha2[1]-alpha2[2]+1);
        ans+=(alpha2[1]-alpha2[2]+1);
        alpha2[1]=alpha2[2]-1;
    }else if(alpha2[1]>0){
        ans+=alpha2[1];
        alpha2[0]-=alpha2[1];
        alpha2[1]=0;

    }else{
        ans+=alpha2[0];
        working=0;
    }
   }
    cout<<ans<<"\n";
   


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
