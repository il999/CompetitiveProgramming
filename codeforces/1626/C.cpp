#include <iostream>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    long long m[n];
    long long h[n];
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    long long mana=0;;
    long long temp_mana=h[0];
    long long last=m[n-1];
    long long cm=m[n-1]-h[n-1];

    for(int i=n-2;i>=0;i--)
    {
        if(m[i]<=cm)
        {

            mana+=((last-cm)*(last-cm+1))/2;
            last=m[i];

        }
        cm=min(m[i]-h[i],cm);
    }
        mana+=((last-cm)*(last-cm+1))/2;
    cout<<mana<<endl;
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
