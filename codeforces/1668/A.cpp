#include <iostream>

using namespace std;

void  solve()
{
    int n,m;
    cin>>n>>m;
    n--;
    m--;
    if((n==0||m==0)&&max(n,m)>1)
    {
        cout<<-1<<"\n";
        return;
    }
    if(n==m)
    {
        cout<<n+m<<endl;
    }else
    {
        if(n%2==m%2)
        {
            cout<<max(n,m)*2<<"\n";
        }else
        {
            cout<<(max(n,m)*2)-1<<"\n";
        }
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
