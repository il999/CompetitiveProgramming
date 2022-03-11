#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n,m;
    cin>>n>>m;
    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    if (s[0][0]=='1')
    {
        cout<<-1<<endl;
        return;
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(s[i][j]=='1')
            {
                c++;
            }
        }
    }
    cout<<c<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>0;j--)
        {
            if(s[i][j]=='1')
            {
                cout<<i+1 <<" "<<j<<" "<<i+1<<" "<<j+1<<"\n";
            }
        }
    }
    for(int i=n-1;i>0;i--)
    {
        if(s[i][0]=='1')
        {
            cout<<i<<" "<<1<<" "<<i+1<<" "<<1<<"\n";
        }
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
