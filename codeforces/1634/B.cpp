#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    long long x,y;
    cin>>x>>y;
    int a[n];
    long long add=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        add+=a[i];
    }
    if((x+add)%2==y%2)
    {
        cout<<"Alice"<<"\n";
    }else
    {
        cout<<"Bob"<<"\n";
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
