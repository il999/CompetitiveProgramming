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
    int n;
    cin>>n;
    int x=0;
    cin>>x;
    int current=0;
    int a[n];
    int b[n];
    int c[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    int i1,i2,i3=0;
    for(int i=0;i<n;i++){
        
        if((a[i]|x)!=x)break;
        current|=a[i];
        i1++;
    }
    for(int i=0;i<n;i++){
        if((b[i]|x)!=x)break;

        current|=b[i];
        i2++;
    }
    for(int i=0;i<n;i++){
        if((c[i]|x)!=x)break;
        current|=c[i];
        i3++;
    }
    if(current!=x){
        cout<<"NO\n";
        return;
    }else{
        cout<<"YES\n";
    }

    
    


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}