//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        ans+=l[i]-1;
    }
    if(ans%2==0)
    {
        cout<<"maomao90"<<"\n";
    }else
    {
        cout<<"errorgorn"<<"\n";
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
