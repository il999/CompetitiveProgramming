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
    int tot=(n*(n-1))/2;

    vector<int> a(tot);
    for(int i=0;i<tot;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int c=1;
    vector<int> actual;
    int number=n-1;
    for(int i=0;i<tot-1;i++){
        if(a[i]==a[i+1]) c++;
        else{
            while(c>0){
                c-=number;
                number--;
                actual.push_back(a[i]);

            }
            c=1;
        }
    }
     while(c>0){
        c-=number;
        number--;
        actual.push_back(a[tot-1]);

    }
       // c=1;
    
    for(int i=0;i<n-1;i++){
        cout<<actual[i]<<" ";
    }
    cout<<1000000000<<"\n";
    

   

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}