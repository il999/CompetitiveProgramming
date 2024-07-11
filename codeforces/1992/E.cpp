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
    //100 friends, 10^5 apples
    int n;
    cin>>n;

    //when is a*n definitely <=10(ndigits*a)
    //only over 5 decimals
    int ndigits=0;
    int n1=n;
    vector<int> digit;
    while(n1>0){
        ndigits++;
        digit.push_back(n1%10);
        n1/=10;
    }
    reverse(digit.begin(),digit.end());
    vector<int> numbers(8);
    int in=0;
    int last=0;
    for(int i=1;i<=7;i++){
        last = last*10 +digit[in];
        numbers[i]=last;
        in++;
        if(in>=digit.size())in=0;
    }
    vector<array<int,2> > pos;
    for(int i=1;i<10001;i++){

        for(int j=ndigits*i-7;j<ndigits*i;j++){
            int wanted= n*i-j;
            int actual = numbers[ndigits*i-j];
            if(wanted==actual&&j!=0&&j<=10000){
                pos.push_back({i,j});
            }
        }
    }
    cout<<pos.size()<<"\n";
    for(int i=0;i<pos.size();i++){
        cout<<pos[i][0]<<" "<<pos[i][1]<<"\n";
    }


}





signed main(){
  //  ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();

}