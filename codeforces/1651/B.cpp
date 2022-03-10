#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    if(n>19)
    {
        cout<<"NO"<<"\n";
            return;
    }
    cout<<"YES"<<endl;
    long long ans=1;
    for(int i=0;i<n-1;i++)
    {
        cout<<ans<<" ";
        ans*=3;
    }
    cout<<ans<<endl;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
    solve();
}
