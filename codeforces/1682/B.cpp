//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int ne[n];
    int p=-1;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        ne[i]=l[i];

    }
    sort(ne,ne+n);
    for(int i=0;i<n;i++)
    {
        if(ne[i]!=l[i])
        {
            if(p==-1)
            {
                p=l[i];
            }else

            {
                p&=l[i];
            }
        }
    }
    cout<<p<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
