#include <iostream>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    long long l[n][n];

    int posi=0;
    int posj=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>l[i][j];
            if(l[i][j]==0)
            {
                posi=i;
                posj=j;
            }
        }

    }
    if(n==1)
    {
        cout<<1<<"\n";
    }else
    {long long tot=0;
            long long tot1=0;
        if(posi>0)
        {

            for(int i=0;i<n;i++)
            {
                tot+=l[posi-1][i];
            }
        }else
        {
            for(int i=0;i<n;i++)
            {
                tot+=l[posi+1][i];
            }
        }
            for(int i=0;i<n;i++)
            {
                tot1+=l[posi][i];
            }
            l[posi][posj]=tot-tot1;
            if(tot1>=tot)
            {
                cout<<-1<<"\n";
            }else
            {
                for(int i=0;i<n;i++)
                {
                    long long temp=0;
                    for(int j=0;j<n;j++)
                    {
                        temp+=l[i][j];
                    }
                    if(temp!=tot)
                    {
                        cout<<-1<<"\n";
                        return;
                    }
                }
                 for(int i=0;i<n;i++)
                {
                    long long temp=0;
                    for(int j=0;j<n;j++)
                    {
                        temp+=l[j][i];
                    }
                    if(temp!=tot)
                    {
                        cout<<-1<<"\n";
                        return;
                    }
                }
                long long temp=0;
                for(int i=0;i<n;i++)
                {
                    temp+=l[i][i];
                }
                if(temp!=tot)
                {
                    cout<<"-1\n";
                    return;
                }
                temp=0;
                for(int i=0;i<n;i++)
                {
                    temp+=l[i][n-i-1];
                }
                 if(temp!=tot)
                {
                    cout<<"-1\n";
                    return;
                }

                cout<<l[posi][posj]<<"\n";


            }

    }
}
int main()
{
    solve();

}
