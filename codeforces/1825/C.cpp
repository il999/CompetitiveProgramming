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
    int n,m;
    cin>>n>>m;
    int a[n];
    vector<int> nums;
    int lefts=0;
    int rights=0;
    map<int,int> m1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0&&m1.find(a[i])==m1.end()){
            nums.push_back(a[i]);
            m1[a[i]]=1;
        }
        else if (a[i]==-2) rights++;
        else if (a[i]==-1) lefts++;
    }
    int pre[m+1];
    pre[0]=0;
    int in=0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<m;i++){
        pre[i+1]=pre[i];
        if(in<nums.size()&&nums[in]==i+1){
            pre[i+1]++;
            in++;
            
        }
    }
    int best=0;
    int temp=0;
    for(int i=0;i<nums.size();i++){
        temp=0;
        int tp2=0;
        temp+=min(m-nums[i],rights+pre[m]-pre[nums[i]]);
        //tp2=pre[nums[i]+min(m-nums[i],rights)]-pre[nums[i]-1-min(nums[i]-1,lefts)];
        temp+=min(nums[i]-1,lefts+pre[nums[i]-1]);
      //  tp2=nums.size()-tp2+1;
        best=max(temp+1,best);
    }
   // cout<<best<<"checking \n";
    //now try all left or all right
    int tp2=0;
    temp=rights;
    tp2=nums.size();
    best=max(min(m,tp2+temp),best);
     tp2=0;
    temp=lefts;
    tp2=nums.size();
    best=max(min(m,tp2+temp),best);
    cout<<best<<"\n";
   


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
