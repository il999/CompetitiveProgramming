
 //coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int ne[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        ne[i]=l[i];
    }
 
    sort(l,l+n);
    int ans=0;
    int c=0;
    int last=-5;
    int in=-5;
    for(int i=0;i<n;i++)
    {
        if(i<n-1)
        {
            if(l[i]==l[i+1]&&last!=l[i])
            {
                ans++;
                last=l[i];
                in=i;
            }else if(last!=l[i])
            {
                c++;
            }
        }else if(last!=l[i])
        {
            c++;
        }
    }
    if(c%2==1)
    {
        cout<<ans+c/2+1<<"\n";
    }else
 
    {
        cout<<ans+c/2<<"\n";
    }
    //cout<<ans<<"\n";
 
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}