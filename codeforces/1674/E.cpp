//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    long long l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    long long ans=10000000;
    long long temp=0;
    for(int i=0;i<n-1;i++)
    {
        if(i<n-1)
        {

            long long ma=max(l[i],l[i+1]);
            long long mi=min(l[i],l[i+1]);
            long long mum=ma-mi;
            if(ma-2*mum<0)
            {
                temp=ma/2;
                if(ma&1)
                {
                    temp++;
                }
                ans=min(temp,ans);
            }
            else if(ma-2*mum==0)
            {
                ans=min(mum,ans);
            }else
            {
                temp=(ma-2*mum)*2;
                if(temp%3==0)
                {
                    temp=temp/3;
                }else
                {
                    temp=(temp/3)+1;
                }
                ans=min(temp+mum,ans);
            }

        }
        //cout<<ans<<"\n";
        if(i>0&&i<n-1)
        {
            temp=min(l[i-1],l[i+1]);
            long long th=max(l[i-1],l[i+1]);
            if((th-temp)%2==0)
            {
                temp+=(th-temp)/2;
            }else
            {
                temp+=(th-temp)/2 +1;
            }
            ans=min(ans,temp);

        }

    }
    sort(l,l+n);
    long long thing=l[0]/2;
    if(l[0]%2>0)
    {
        thing++;
    }
    thing+=l[1]/2;
    if( l[1]&1)
    {
        thing++;
    }
    ans=min(thing,ans);
    cout<<ans<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
}
