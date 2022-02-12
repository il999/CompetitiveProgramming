#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    bool pos=false;
    long long ans=0;
    bool two=0;
    for(int i=1;i<n-1;i++)
    {
        if(a[i]%2==0)
        {
            pos=true;

        }
        if(a[i]>2)
        {
            two=true;
        }
        ans+=(a[i]+1)/2;
    }
    if(pos||(n>3&&two))
    {
        cout<<ans<<"\n";
    }else
    {
        cout<<-1<<endl;
    }







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
