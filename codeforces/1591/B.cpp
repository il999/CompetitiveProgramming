#include <iostream>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int max1=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        max1=max(max1,l[i]);
    }
    int val=l[n-1];
    long long count1=0;
    if(val!=max1)
    {
        count1++;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(l[i]==max1)
        {
            break;
        }else if(l[i]>val)
        {
            count1++;
            val=l[i];
        }
    }
    cout<<count1<<endl;
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
