//coding template
#include <bits/stdc++.h>
const int mod=998244353 ;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    long long ans=0;
    int co=0;
    long long tempans=1;
    long long tempans2=1;
    int odd=0;
    int even=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==0)
        {
            even++;
            tempans=(tempans*even)%mod;
        }else
        {
            odd++;
            tempans2=(tempans2*odd)%mod;
        }
    }
    if(odd>even)
    {
        cout<<0<<endl;
        return;
    }
    cout<<(tempans*tempans2)%mod<<"\n";
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();

}
