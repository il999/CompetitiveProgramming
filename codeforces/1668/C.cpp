//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];

    }
    long long last=0;
    long long c=0;
    long long ans=-1;
    for(int i=0;i<n;i++)
    {
        c=0;
        if(i>0)
        {
             last=l[i-1];
            c=1;
        }

        for(int j=i-2;j>=0;j--)
        {



            c+=last/l[j];
            c++;
            last=(l[j])*(last/l[j]+1);
        }
        if(i<n-1)
        {
            last=l[i+1];
        c++;
        }


        for(int j=i+2;j<n;j++)
        {

            c+=last/l[j];
            c++;
            last=(l[j])*((last/l[j])+1);

        }
        if(ans==-1)
        {
            ans=c;
        }
        ans=min(ans,c);
    }
    cout<<ans<<"\n";
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
