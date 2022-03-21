//coding template
#include <bits/stdc++.h>
long long factorial[20];
int c;
using namespace std;
int m1;
void recur(int i,long long n,int op)
{
    //cout<<i<<endl;
    if(i==0)
    {
        return;
    }
    if(n-factorial[i]>=0)
    {
        m1=min(m1,__builtin_popcountll(n-factorial[i])+op+1);
        recur(i-1,n-factorial[i],op+1);
    }
    recur(i-1,n,op);
}
void solve()
{
    long long n;
    cin>>n;
     m1=__builtin_popcountll(n);
    //cout<<__builtin_popcountll(n)<<"\n";
    recur(c,n,0);
    cout<<m1<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    long long s=1;
    c=1;
    while(s<1000000000001)
    {
        c++;
        s*=c;
        factorial[c]=s;
    }
    while(t--)
        solve();
}
