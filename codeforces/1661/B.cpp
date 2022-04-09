//coding template
#include <bits/stdc++.h>
using namespace std;
const int mod=32768;
void solve()
{

    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    long long ans=0;
    int c=0;
    int div[32769];

    for(int i=1;i<=mod;i++)
    {
        div[i]=i;
        int c=0;
        int m=mod-div[i];

         while(div[i]%2==0&&div[i]>0)
         {
             div[i]/=2;
             c++;

         }
         div[i]=min(m,15-c);
    }
    for(int i=0;i<n;i++)
    {

        int thing=0;
        int m=div[l[i]];
        while(l[i]!=0)
        {
            for(int j=0;j<=15;j++)
            {
            if(l[i]+j<=mod&&div[l[i]+j]+j+thing<m)
            {
                m=min(m,div[l[i]+j]+j+thing);
            }

            }
            thing++;
            l[i]*=2;
            l[i]%=mod;
        }

        l[i]=m;



    }
    for(int i=0;i<n;i++)
    {
        cout<<l[i]<<" ";
    }
    cout<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();
}
