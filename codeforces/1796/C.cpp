
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
    int l,r;
    cin>>l>>r;
    int tp=l;
    int c=1; 
    int two=1;
    while(tp*2<=r){
        c++;
        tp*=2;
        two*=2;
    }
    int thing=0;
   
    ll low=l;
   ll high=r+1;
   ll lastwork=-1;
    while(low<high){
        ll mid=(low+high)/2;
        if((mid*(two))<=r){
            lastwork=mid;
            low=mid+1;
        }else{
            high=mid;
        }
   }
   if(lastwork!=-1)thing=add(lastwork-l+1,thing);
   else if(l*two<=r)thing=add(thing,1);
   //bool three=false;
    low=l;
    high=r+1;
    lastwork=-1;
   while(low<high){
    ll mid=(low+high)/2;
    if((mid*(two/2)*3)<=r){
        lastwork=mid;
        low=mid+1;
    }else{
        high=mid;
    }
   }
   
   if(lastwork!=-1) thing=add(thing,mul(lastwork-l+1,c-1));
   else if(l*(two/2)*3<=r)thing=add(thing,c-1);



  
   
    cout<<c<<" "<<thing<<"\n";


 
    
    
}
int main()
{
     ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
}