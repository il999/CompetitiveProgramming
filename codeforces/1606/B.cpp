#include <iostream>

using namespace std;
void solve()
{

    long long n,k;
    cin>>n>>k;

    long long ans=1;

    long long i=0  ;
    long long counter=0;
    while(ans+(min(ans,k))<=n)
    {
        ans+=min(ans,k);
        i++;
        if(k<ans)
        {
            cout<<i+((n-ans+k-1)/k)<<endl;
            return;
        }

    }
    if(ans!=n)
    {
        i++;

    }


    cout<<i<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
