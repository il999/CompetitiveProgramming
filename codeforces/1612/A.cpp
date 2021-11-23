#include <iostream>

using namespace std;
void solve()
{
    int x,y;
    cin>>x>>y;
    if((x+y)%2==1)
    {
        cout<<-1<< " "<<-1<<endl;
    }else
    {
        if(x%2==1)
        {
            x++;
        }
        cout<<(x)/2<<" "<<(y)/2<<endl;
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
