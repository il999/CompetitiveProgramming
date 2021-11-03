#include <iostream>

using namespace std;
void solve()
{
    long long a,b;
    cin>>a>>b;
    if(a%2==0)
    {
        if(b%2==1)
        {
            if((b/2)%2==0)
            {
                cout<<a-b<<endl;
            }else
            {
                cout<<a+b+1<<endl;
            }

        }else
        {
            if((b/2)%2==0)
            {
                cout<<a<<endl;
            }else
            {
                cout<<a+1<<endl;
            }
        }
    }else
    {
        if(b%2==0)
        {
            if((b/2)%2==0)
            {
                cout<<a<<endl;
            }else
            {
                cout<<a-1<<endl;
            }

        }else
        {
            if((b/2)%2==0)
            {
                cout<<a+b<<endl;
            }else
            {
                cout<<a-b-1<<endl;
            }
        }
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
