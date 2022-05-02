//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int a[n];
    int poop[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        poop[i]=a[i];
    }
    sort(poop,poop+n);
    bool used[n]={0};
    for(int i=n-1;i>=0;i-=2)
    {
        if(i==0)
        {
            break;
        }
         if(a[i]!=poop[i])
         {
                if(a[i-1]!=poop[i]||a[i]!=poop[i-1])
                {
                    cout<<"NO\n";
                    return;
                }
         }
         else if(a[i-1]!=poop[i-1])
         {
             cout<<"NO\n";
             return;
         }
    }
    if(n%2==1&&a[0]!=poop[0])
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES \n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
