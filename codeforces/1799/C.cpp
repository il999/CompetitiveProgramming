
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
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
    string s;
    cin>>s;
    int n;
    n=s.size();
    vector<int> alpha(27);
    string front="";
    string back="";
    int pre[27];
    pre[26]=0;
    for(int i=0;i<n;i++)
    {
        alpha[s[i]-'a']++;
    }
    for(int i=25;i>=0;i--){
        pre[i]=pre[i+1];
        if(alpha[i]>0)pre[i]++;
    }
    if(n==1){
        cout<<s<<"\n";
        return;
    }
    bool done=0;
    int to_add=-1;
    for(int i=0;i<26;i++){
        if(alpha[i]>0){
            if(alpha[i]%2==0){
                for(int j=0;j<alpha[i]/2;j++){
                    front+='a'+i;
                    back+='a'+i;
                }
           }else{
                for(int j=0;j<alpha[i]/2;j++){
                    front+='a'+i;
                    back+='a'+i;
                }
            
                if(pre[i+1]==1){
                    to_add=i;
                    for(int j=i+1;j<26;j++){
                        if(alpha[j]>0){
                            if(alpha[j]%2==1){
                                front+='a'+j;
                            }
                            for(int k=0;k<alpha[j]/2;k++){
                                front+='a'+j;
                                back+='a'+j;
                                //cout<<j<<"\n";
                            }
                        }
                    }
                    i=77;
                    break;
                   // cout<<"\n"<<s<<"\n";
                  //  cout<<front<<" "<<back<<"\n";
                    //cout<<"IAM ?HER\n";
                }else{
                    front+='a'+i;
                    done=1;
                    alpha[i]=0;
                    i=77;
                    break;
                }
           }
        }
        alpha[i]=0;
    }
    if(done){
        for(int i=0;i<26;i++){
            while(alpha[i]>0&&back.size()<n/2+n%2){
                back+=i+'a';
                alpha[i]--;
            }
        }
        for(int i=25;i>=0;i--){
            while(alpha[i]>0&&front.size()<n/2){
                front+=i+'a';
                alpha[i]--;
            }
        }
    }
    if(to_add>=0) front+='a'+to_add;
    string p="";
    for(int i=back.size()-1;i>=0;i--){
        p+=back[i];
    }
    string thin=front+p;
    
        string ne=back;
        for(int i=front.size()-1;i>=0;i--){
            ne+=front[i];
        }
    if(thin>ne){
        ne=thin;
    }

    cout<<ne<<"\n";
    
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}