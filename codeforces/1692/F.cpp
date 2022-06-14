//coding template
#include <bits/stdc++.h>
using ll =long long;
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int m[10];
    for(int i=0;i<10;i++)
        m[i]=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        m[l[i]%10]++;
    }
    for(int i=0;i<10;i++)
    {
       // cout<<m[i]<<" ";
    }
    //cout<<"\n";
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                if((i==j&&j==k)||m[i]==0||m[j]==0||m[k]==0)
                {
                    if(i==j&&j==k&&i==1&&m[i]>=3)
                    {
                         cout<<"YES\n";
                         return;
                    }
                }else
                {
                    if((i+j+k)%10==3&&m[i]>0&&m[j]>0&&m[k]>0)
                    {
                        if(i==j||k==i)
                        {
                            if(m[i]>=2)
                            {
                                cout<<"YES\n";
                                return;
                            }
                        }else if(j==k)
                        {
                            if(m[j]>=2)
                            {
                                cout<<"YES\n";
                                return;
                            }
                        }else
                        {
                            //cout<<i<<" "<<j<<" "<<k<<"\n";
                            cout<<"YES\n";
                                return;
                        }
                    }
                }
            }
        }
    }
    cout<<"NO\n";
    return;

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
