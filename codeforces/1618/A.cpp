#include <iostream>

using namespace std;
void solve()
{
    int l[7];
    for(int i=0;i<7;i++)
    {
        cin>>l[i];

    }
    cout<<l[0]<<" "<<l[1]<<" ";
    if(l[0]+l[1]==l[2])
    {
        cout<<l[3]<<endl;
    }else
    {
        cout<<l[2]<<endl;
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
