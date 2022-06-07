//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    // cout<<((n+3)/3)<<" ";
    int first=(((n+3)/3));
    if((n+3)%3!=0)
    {
        first++;
    }

    int second=0;
    int n2=n-first;
    if(n2%2==0)
    {
        cout<<n2/2+1<<" "<<first<<" "<<n2/2-1<<"\n";
    }else

    {
           cout<<n2/2+1<<" "<<first<<" "<<n2/2<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
