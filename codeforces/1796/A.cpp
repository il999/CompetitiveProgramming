
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
    
    string s;
    cin>>s;
    string FB="";
    for(int i=1;i<=200;i++){
        
        if(i%3==0) FB+='F';
         if(i%5==0) FB+='B';
    }
    string temp="";
    for(int i=0;i<FB.size();i++){
        temp+=FB[i];
        if(temp.size()==s.size()){
            if(temp==s){
                cout<<"YES\n";
                return;
            }else{
                string temp2="";
                for(int j=1;j<temp.size();j++) temp2+=temp[j];
                temp=temp2;
            }
        }
    }
    cout<<"NO\n";
    //cout<<FB<<"\n";



 
    
    
}
int main()
{
     ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin>>t;
    while(t--)
        solve();
}