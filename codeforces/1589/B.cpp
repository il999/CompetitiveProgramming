#include <iostream>

using namespace std;
void solve()
{
    long long n,m;
    cin>>n>>m;
    long long ans=m/3;
    ans=ans*n;
    long long ans1=n*m;
    long long ans2=0;
    long long amount=m%3;
    if(n%3==0)
    {
        ans1=ans+((n/3)*(m%3));
    }
    long long one=1;
    ans2=ans+(((n/3)+(min(one,n%3)))*(amount));
    //cout<<(min(one,n%3))*(amount)<<endl;
    long long ans21=n*m;
    long long ans22=0;
    long long ans23=n/3;
    ans23*=m;
    amount=n%3;
    if(m%3==0)
    {
        ans21=ans23+((m/3)*(n%3));
    }

        ans22=ans23+((((m/3)+(min(one,m%3)))*(amount)));
        //cout<<ans1<<" "<<ans2<<" "<<ans21<<" "<<ans22<<endl;
        cout<<min(min(ans1,ans2),min(ans21,ans22))<<endl;


}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
