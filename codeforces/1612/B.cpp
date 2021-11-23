#include <iostream>

using namespace std;
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    if((((n/2)<b)||(n/2==b&&a==(n/2)+1))&&((a<(n/2)+1)||(a==(n/2)+1&&b<=n/2)))
    {
        cout<<a<<" ";
        for(int i=n;i>n/2;i--)
        {
            if(i!=b&&i!=a)
            {
                cout<<i<<" ";
            }
        }




        for(int i=1;i<=n/2;i++)
        {
            if(i!=b&&i!=a)
            {
                cout<<i<<" ";
            }
        }

        cout<<b<<" ";
        cout<<endl;

    }else
    {
        cout<<-1<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
