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
void solve() {
    int n;
    cin>>n;
    vector<vector<int> > cake(3,vector<int>(n));
    for(int i=0;i<3;i++)
        for(int j=0;j<n;j++) cin>>cake[i][j];
    int tot=0;
    for(int i=0;i<n;i++){
        tot+=cake[0][i];
    }
    tot = (tot+2)/3;
    vector<vector<int> > pre(3,vector<int>(n+1));
    vector<vector<int> > suf(3,vector<int>(n+1));
    vector<int> prFirst(3,-1);
    vector<int> sfFirst(3,-1);
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            pre[i][j+1]=pre[i][j]+cake[i][j];
            if(prFirst[i]==-1&&pre[i][j+1]>=tot) prFirst[i]=j;
        }
        for(int j=n-1;j>=0;j--){
            suf[i][j] = suf[i][j+1]+cake[i][j];
            if(sfFirst[i]==-1&&suf[i][j]>=tot) sfFirst[i]=j;
        }
      //  cout<<suf[i][0]<<"\n";
       //cout<<prFirst[i]<<" "<<sfFirst[i]<< " hello\n";
    }
    vector<int> t ={0,1,2};
    vector<array<int,2> > ans(3, {-1,-1});
    do{
        int mid =t[2];
        if(pre[mid][sfFirst[t[1]]]-pre[mid][prFirst[t[0]]+1]>=tot){
            //cout<<pre[mid][sfFirst[t[1]]]-pre[mid][prFirst[t[0]]+1]<<"\n";
            ans[mid][0]=prFirst[t[0]]+2;
            ans[mid][1]=sfFirst[t[1]];
            ans[t[1]][0]=sfFirst[t[1]]+1;
            ans[t[1]][1]=n;
            ans[t[0]][0]=1;
            ans[t[0]][1]=prFirst[t[0]]+1;
            break;
        }
    }while(next_permutation(t.begin(),t.end()));
    if(ans[0][0]==-1){
        cout<<-1<<'\n';
    }else{
        for(int i=0;i<3;i++){
            cout<<ans[i][0]<<" "<<ans[i][1]<<" ";
        }
        cout<<"\n";
    }


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}