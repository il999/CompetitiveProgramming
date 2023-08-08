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
    //au-bu>av-bv
    int a[n];
    int b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    array<int,2> tp;
     vector<array<int,2> > v;
    for(int i=0;i<n;i++){
        tp[0]=a[i]-b[i];
        tp[1]=i+1;
        v.push_back(tp);
    }
   
    sort(v.rbegin(),v.rend());
    int c=1;
    vector<int> ans;
    ans.push_back(v[0][1]);
   // cout<<v[0][1]<<" ";
    while(c<n&&v[c][0]==v[0][0]){
        //c++;
        //cout<<v[c][1]<<" ";
        ans.push_back(v[c][1]);
        c++;
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    

   

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}