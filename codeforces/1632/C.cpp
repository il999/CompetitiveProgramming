#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a,b;
    cin>>a>>b;

    long long ans=b-a;
  int or1;
   //cout<<or1<<endl;
    for(long long i=a;i<b;++i)
    {
        //cout<<i|b<<"\n";
          or1=i|b;
        if(or1==b)
        {

            ans=min(ans,i-a+1);
            break;
        }
    }
    for(long long i=b+1;;++i)
    {
        or1=a|i;
        if(or1==i)
        {

            ans=min(ans,i-b+1);
            break;
        }
    }
    cout<<ans<<"\n";
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
