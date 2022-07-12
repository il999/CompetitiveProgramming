//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int> v;
    vector<int> v2;
    int a;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a<=i)
        {
            v.push_back(i+1);
            v2.push_back(a);
            m[a]=1;


            //now find amountp of number in this greater than that;
        }
    }

    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());

    long long ans=0;
    for(int i=0;i<v.size();i++)
    {
        int low=0;
        int high=v2.size()-1;

        while(low<high)
        {
            int mid=(low+high)/2;
            if(v2[mid]<=v[i])
            {
                low=mid+1;
            }else
            {
                high=mid;
            }
        }
        int p=v.size();
        if(v2[high]>v[i])
        {
            ans+=v.size()-high;
        }


    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
