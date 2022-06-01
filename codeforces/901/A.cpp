//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int h[n+1];
    bool mroe=false;
    for(int i=0;i<n+1;i++)
    {
        cin>>h[i];
        if(i>0&&h[i-1]>1&&h[i]>1)
        {
            mroe=true;
        }
    }
    if(!mroe)
    {
        cout<<"perfect\n";

    }else
    {
        cout<<"ambiguous\n";
        long long pre[n+2];
        pre[0]=0;
        for(int i=0;i<n;i++)
        {
            pre[i+1]=pre[i]+h[i];
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<h[i];j++)
            {
                if(i>0)
                {
                    cout<<pre[i]-h[i-1]+1<<" ";
                }else
                {
                     cout<<pre[i]<<" ";
                }

            }

        }
        cout<<"\n";
        bool done=false;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<h[i];j++)
            {
                if(h[i]>1&&i>0&&h[i-1]>1&&!done)
                {
                    done=true;
                    cout<<pre[i]+1-h[i-1]+1<<" ";
                }else
                {
                    if(i>0)
                    {
                        cout<<pre[i]-h[i-1]+1<<" ";
                    }else
                    {
                        cout<<pre[i]<<" ";
                    }

                }

            }

        }
        cout<<"\n";
    }


}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

        solve();
}
