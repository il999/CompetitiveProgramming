#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++)
        cin>>l[i];
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(l[i]==0)
            c++;
    }

    if(c==n)
    {
        cout<<0<<"\n";
        return;
    }

    if(c==1&&(l[0]==0||l[n-1]==0))
    {
        cout<<1<<"\n";
        return;
    }
    if(c==2&&(l[0]==0&&l[n-1]==0))
    {
        cout<<1<<"\n";
        return;
    }

    if(c==0)
    {
        cout<<1<<"\n";
        return;
    }
    int amount=0;
    bool c1=0;
    for(int i=0;i<n;i++)
    {
        if(l[i]!=0&&!c1)
        {
            c1=1;
       // cout<<"hi";
            amount++;
        }else if(c1&&l[i]==0)
        {

            c1=false;
        }
    }
    if(amount==1)
    {
        cout<<1<<"\n";
        return;
    }
    cout<<2<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
