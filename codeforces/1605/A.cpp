#include <iostream>

using namespace std;
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    if((a+b+c)%3==0)
    {
        cout<<0<<endl;
    }else
    {
        cout<<1<<endl;
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
