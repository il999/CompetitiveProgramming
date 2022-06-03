//coding template
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int  N = 2e5+1;
int f[N];

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int mul(int a, int b) { return (1LL*a*b)%MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) { return mul(a,binpow(b,MOD-2)); }

int sub(int a, int b) { return add(a,MOD-b); }

void calc_factorials() {
    f[0]=1;
    for (int i=1;i<N;++i) f[i]=mul(f[i-1],i);
}









void solve()
{
    int k,n;
    cin>>n>>k;
   int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    sort(l,l+n);
    int last=l[n-1];
    for(int i=n-1 ;i>n-k;i--)
    {
        if(l[i]!=l[i-1])
        {
            last=l[i-1];
        }
    }
    int li=0;
    int inrange=0;
    for(int i=0;i<n;i++)
    {
        if(l[i]==last)
        {
            li++;
        }
        if(l[i]==last&i>=n-k)
        {
            inrange++;
        }
    }

    cout<<dv(f[li],mul(f[li-inrange],f[inrange])) <<"\n";
}
int main()
{

calc_factorials();
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
