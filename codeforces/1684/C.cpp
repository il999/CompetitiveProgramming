//coding template
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m;
    cin>>n>>m;
    int l[n][m];
    int l2[m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>l[i][j];

        }
    }
    int p=-1;
    bool wrong[m]={0};
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<m;j++)
        {
            l2[j]=l[i][j];
        }
        sort(l2,l2+m);
         for(int j=0;j<m;j++)
        {
            if(l2[j]!=l[i][j])
            {
                wrong[j]=true;
                p=i;
            }
        }
    }
    int j1=-2;
    int i1=-2;
    int c=0;
    for(int i=0;i<m;i++)
    {
        if(wrong[i]==true)
        {
            c++;
            if(i1==-2)
            {
                i1=i;
            }else
            {
                j1=i;
            }
        }
    }

    if(c>2)
    {
        cout<<-1<<"\n";
        return;
    }else if(c==2)
    {


        int temp=0;
        for(int i=0;i<n;i++)
        {
            temp=l[i][i1];
            l[i][i1]=l[i][j1];
            l[i][j1]=temp;
        }
       // cout<<"DGSA2";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            l2[j]=l[i][j];
        }
        sort(l2,l2+m);
         for(int j=0;j<m;j++)
        {
            if(l2[j]!=l[i][j])
            {
                cout<<-1<<"\n";
                return;
            }
        }
    }
    cout<<i1+1<<" "<<j1+1<<"\n";
    }else if(c==0)
    {
        cout<<1<<" "<<1<<"\n";
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
