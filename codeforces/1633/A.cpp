#include <iostream>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    int mod=n%7;
    int thing=n%10;
    if(n<10)
    {
        cout<<7<<endl;
    }
    if(thing-mod>=0)
    {
       // cout<<"GDsag"<<endl;
        cout<<n-mod<<endl;

    }
    else if(thing+(7-mod)<10)
    {
        cout<<n+(7-mod)<<endl;
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
