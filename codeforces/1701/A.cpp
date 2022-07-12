//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
   n=2;
    int l[2][2];
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>l[i][j];
            if(l[i][j]==1)
            {
                c++;
            }
        }
    }
    if(c==4)
    {
        cout<<2<<"\n";

    }else if(c==0)
    {
        cout<<0<<"\n";

    }else
    {
        cout<<1<<"\n";
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
