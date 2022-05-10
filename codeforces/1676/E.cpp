//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,q;
    cin>>n>>q;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    sort(l,l+n,greater<int>());
    int pre[n+1];
    pre[0]=0;
    for(int i=0;i<n;i++)
    {
        pre[i+1]=pre[i]+l[i];
    }
    for(int i=0;i<q;i++)
    {
        int s;
        cin>>s;
        int low=0;
        int high=n;
        int mid=0;
        while(low<high)
        {
            mid=(low+high)/2;
            if(pre[mid]==s)
            {
                low=high;
            }else if(pre[mid]<s)
            {
                low=mid+1;
            }else
            {
                high=mid;
            }
        }
        if(mid>0&&pre[mid-1]>=s)
        {
            mid--;
        }
        if(pre[mid]<s&&mid<n)
        {
            mid++;
        }
        if(pre[mid]<s)
        {
            cout<<-1<<"\n";
        }else
        {
             cout<<mid<<"\n";
        }

    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
