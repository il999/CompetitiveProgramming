
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
    int n;
    cin>>n;
    //have a string 26 characters long
    //if character there and odd occurences 1, if character there and even occurences 0, if character not there 1;
    map<string,int> m;
    ll ans=0;
    string s[n];
    vector<vector<int> > alpha (n,vector<int>(26));
    vector<int> bin(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<s[i].size();j++)alpha[i][s[i][j]-'a']++;
    }
   // cout<< (1<<4) <<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            //cout<<alpha[i][j]<<"   !  ";
            if((alpha[i][j]%2)==1)bin[i]|=(1<<j);

        }
        //cout<<bin[i]<<"\n";
    }
    
    for(int i=0;i<26;i++){
        map<int,int> m;
        for(int j=0;j<n;j++){
            if(alpha[j][i]==0){
                //check alternate
                int alternate=0;
                for(int k=0;k<26;k++){
                    if(!(bin[j]&(1<<k))&&k!=i)alternate|=(1<<k);
                }
                //cout<<(alternate^bin[j])<<"\n";
                if(m.find(alternate)!=m.end()) ans+=m[alternate];
                if(m.find(bin[j])==m.end()){
                    m[bin[j]]=1;
                }else{
                    m[bin[j]]++;
                }
            }
        }
       //cout<<ans<<"\n";
    }
    cout<<ans<<"\n";
   

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    
        solve();
}