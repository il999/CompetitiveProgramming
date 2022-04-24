//coding template
#include <bits/stdc++.h>
using namespace std;
const long long inf=31241243144334;
void solve()
{
    long long n,x;
    cin>>n>>x;
    long long l[n];
    long long mi,ma;

    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    mi=l[0];
    int inmin=0;
    int inmax=0;
    ma=l[0];
    for(int i=1;i<n;i++)
    {
        if(l[i]<mi)
        {
            mi=l[i];
            inmin=i;
        }
         if (l[i]>ma)
        {
            ma=l[i];
            inmax=i;
        }
    }
    long long zero=0;
    long long above=max(x-ma,zero);
    long long below=mi-1;
    long long cost=0;
    for(int i=1;i<n;i++)
    {
        cost+=abs(l[i]-l[i-1]);
    }
    long long pos=inf;
    if(above>0)
    {
        //go to max edge of array
        //or got to the max neighbours of the max
        if(inmax>0)
        {
            pos=(above+x-l[inmax-1])-(l[inmax]-l[inmax-1]);
        }

        if(inmax<n-1)
        {
            pos=min(pos,(above+x-l[inmax+1])-(l[inmax]-l[inmax+1]));
        }

        pos=min(pos,abs(max(l[0],l[n-1])-(ma+1))+above-1);

    }
    if(pos==inf)
    {
        pos=0;
    }
    //cout<<"POS1=0"<<pos<<"\n";

    cost+=pos;
    pos=inf;
    if(mi>1)
    {
        if(inmin>0)
        {
            pos= -(l[inmin-1]-l[inmin])+l[inmin-1]-1+(mi-1);
        }
        if(inmin<n-1)
        {
            pos= min(pos,-(l[inmin+1]-l[inmin])+(mi-1)+l[inmin+1]-1);
        }
        pos=min(pos,min(l[0],l[n-1])-min(mi-1,x)+min(mi-2,x-1));
        //cout<<pos;
    }
    if(pos==inf)
    {
        pos=0;
    }
   // cout<<pos<<"POS2\n";
    cout<<pos+cost<<"\n";


}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
