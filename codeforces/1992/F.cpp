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
int gcd(int a,int b){
    if(a<b)swap(a,b);
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
vector<int> primes;
void solve() {
    //100 friends, 10^5 apples
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    // decompose prime number x, basically we need the product of each segment to not be multiple of x;
    //maximum 17 primes,
    //each number added to a subset where its numebered by bitly by which primes it has, number, if x divides y no reason to not have in same group
    //now we have unique groups of numbers, ng
    vector<array<int,2> > decomp;
    // we jsut need avoid where the knapsack dp creates x, otherwise we g, these 3 cant be in a thing together, hen submit wihtout that?
    for(int div : primes){
        int tp = x;
        int num=0;
        while(tp%div==0) {
            num++;
            tp/=div;
        }
        if(num!=0)decomp.push_back({div,num});
    }
    int segments=1;
    vector<int> looking;
    vector<vector<int> > sofar;
    sofar.push_back(vector<int>());
    for(int i=0;i<decomp.size();i++){
        looking.push_back(decomp[i][1]);
        sofar[0].push_back(0);
    }
 //   cout<<"HER\n";
    map<vector<int> ,int> seen;
    for(int i=0;i<n;i++){
       // cout<<"HERe";
        vector<array<int,2> > dpnew;
        if(gcd(a[i],x)!=a[i]) continue;
        if(a[i]==1) continue;
        vector<int > comp;
        //cout<<"HER";
        for(auto div :decomp){
            int tp =a[i];
            int num=0;
            while(tp>0&&tp%div[0]==0){
                num++;
                tp/=div[0];
            }
            comp.push_back(num);
        }
        int now=sofar.size();
        for(int i=0;i<now;i++){
            vector<int> ne;
            bool work=true;
            for(int j =0;j<sofar[i].size();j++){
                if(sofar[i][j]+comp[j]<=looking[j]){
                    ne.push_back(sofar[i][j]+comp[j]);
                }else{
                    work=false;
                    break;
                }
            }
            if(work&&seen.find(ne)==seen.end()){
                sofar.push_back(ne);
                seen[ne] = 1;
            }
        }
        if(seen.find(looking)!=seen.end()){
         //   cout<<i<<"\n";
            seen.erase(seen.begin(),seen.end());
            sofar.erase(sofar.begin(),sofar.end());
            sofar.push_back(comp);
            sofar.push_back(vector<int>(looking.size()));
            seen[comp]=1;
            segments++;
        }



    }
    cout<<segments<<"\n";
}





signed main(){
  //  ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
   vector<bool> isPrime(100001,1);
   for(int p=2; p<=100000;p++){
       if(isPrime[p]){
           primes.push_back(p);
           for(int i=p*p;i<=100000;i+=p){
               isPrime[i]=false;
           }
       }
   }
    int t;
    cin>>t;
    while(t--)
        solve();

}