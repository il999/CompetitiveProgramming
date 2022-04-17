//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int r,b;
    cin>>r>>b;
    int both=r+b;

    int recur=r/(b+1);
   if(r%(b+1)!=0)
   {
       recur++;
   }

    int c=0;
    int par=0;
    //bool p=true;
    int p=0;
    int needed=(r%(b+1));
    bool done=false;
    for(int i=0;i<both;i++)
    {
        if(p==needed&&!done&&needed!=0)
        {
            recur--;
            done=true;
        }
        if(c<recur&&r>0)
        {
            c++;
            cout<<'R';
            r--;
        }else
        {
            p++;
            cout<<'B';
            c=0;
            b--;
        }
    }
    cout<<"\n";
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
