#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    int r=0;
    if(n%3==1)
    {
        r=1;
    }else if(n%3==2)
    {
        r=0;
    }
    int p=(n/3)*2;

    if(n%3!=0)
    {
        p++;
    }


    for(int i=0;i<p;i++)
    {
        if(i%2==r)
        {
            cout<<"2";
        }else
        {
            cout<<"1";
        }
    }
    cout<<"\n";
}
int main()
{
    int t;
    cin >>t;
    while(t--)
        solve();
}
