//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,x;
    cin>>n>>x;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];

    }
    long long pre[n+1];
    pre[0]=0;
    sort(l,l+n);
    for(int i=0;i<n;i++)
    {
        pre[i+1]=pre[i]+l[i];
    }
    long long days=0;
    long long tax=0;
    long long ans=0;
    long long poop=0;
    for(int i=n;i>0;i--)
    {
        tax=i*days;
        if(pre[i]+tax<=x)
        {

            poop=(x-(pre[i]+tax))/i;

                poop++;

            ans+=poop*i;
            days+=poop;
            //cout<<days<<"\n";
        }
    }
    cout<<ans<<"\n";

}
int main()
{
   //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
