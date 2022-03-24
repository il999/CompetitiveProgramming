//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];

    }
    sort(l,l+n);
    int count1=0;
    for(int i=0;i<n;i++)
    {
        int low=0;
        int high=n-1;
        int mid=low;
        while(low<high)
        {
            mid=(low+high)/2;
            if(l[mid]==l[i]-k)
            {
                cout<<"YES"<<endl;
                return;
            }else if(l[mid]<l[i]-k)
            {
                low=mid+1;
            }else
            {
                high=mid;
            }
        }

    }
    cout<<"NO"<<"\n";
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
