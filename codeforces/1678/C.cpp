//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int ar[n+1][n+1]={{0}};
      for(int i=n;i>=0;i--)
    {
        for(int j=0;j<=n;j++)
        {
            ar[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    for(int i=n-1;i>=0;i--)
    {

        for(int j=0;j<=n;j++)
        {

            ar[i][j]=ar[i+1][j];
            if(j>=l[i])
                ar[i][j]++;
        }

    }
    long long ans=0;
    long long last=0;
    long long realans=0;
    int aff[n+1];
    bool done=false;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+2;j<n-1;j++)
        {

            last-=(j-i-1)-(ar[i+1][l[j]-1]-ar[j][l[j]-1]);
            //cout<<l[i]<<" "<<l[j]<<" "<<(j-i-1)-(ar[i+1][l[j]-1]-ar[j+1][l[j]-1])<<"\n";
            //cout<<last<<"\n";

                    last+=ar[j][l[j-1]-1];

            if(l[j]>l[i])
            {
                if(!done)
                {
                    for(int k=i+1;k<j;k++)
                    {
                        ans+=ar[j+1][l[k]-1];
                    // cout<<l[k]<<" amount less than :"<<ar[j][l[k]-1]<<"\n";
                    }
                    last=ans;
                    done=true;
                }


                long long z=0;
                //cout<<last<<"\n";
                realans+=last;
            }

        }
        ans=0;
        done=false;
    }
    cout<<realans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
