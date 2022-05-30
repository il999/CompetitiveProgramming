//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;

    long long a,b,c;
    cin>>a>>b>>c;

    cout<<a+b+c<<" "<<c+b<<" "<<c<<"\n";
    //cout<<(a+b+c)%(c+b)<<" "<<(c+b)%c<<" "<<c%(a+b+c)<<"\n";


}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
