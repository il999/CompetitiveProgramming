#include <iostream>

using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    int counter=0;
    if(k==1)
    {
        cout<<"YES"<<"\n";
        for(int i=0;i<n;i++)
        {
            cout<<i+1<<"\n";
        }
        return;
    }
    if(n%2==0)
    {
        int counter=1;
        cout<<"YES"<<"\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                cout<<counter<<" ";
                counter+=2;
            }
            cout<<"\n";
            if(counter>=n*k)
            {
                counter=2;
            }
        }
    }else
    {
        cout<<"NO"<<endl;
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
