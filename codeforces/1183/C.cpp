//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long k,n,a,b;
    cin>>k>>n>>a>>b;
    long long q=-1;
    long long low=0;
    long long high=n;
    long long mid=0;

    while(low<high)
    {
        mid=(low+high)/2;

         if((k-(b)*mid)%a!=0&&(k-(b)*mid)/a>=n-mid)
        {
            q=n-mid;
            high=mid;
        }else if((k-(b)*mid)/a>n-mid)
        {
            q=n-mid;
            high=mid;
        }else
        {
            low=mid+1;
        }
    }
    long long z=0;
    if(k-n*b>0)
    {
        q=max(q,z);
    }



    cout<<q<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
