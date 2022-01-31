#include <iostream>

using namespace std;
void solve()
{
    string s;
    cin>>s;
    int ones=0;
    int zeros=0;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            zeros++;
        }else
        {
            ones++;
        }
    }
    if(ones==zeros)
    {
        if(zeros!=1)
        {
            cout<<zeros-1<<"\n";
        }else
        {
            cout<<0<<"\n";
        }
    }else
    {
        cout<<min(zeros,ones)<<"\n";
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
