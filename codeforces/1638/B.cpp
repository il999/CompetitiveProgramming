#include <bits/stdc++.h>

using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    int odd=0;
    int even=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];

    }

    for(int i=0;i<n;i++)
    {

        if(l[i]%2==0)
        {
            if(l[i]<even)
            {
                cout<<"NO"<<"\n";
                return;
            }

            even=l[i];

        }else
        {
            if(l[i]<odd)
            {
                cout<<"NO"<<"\n";
                return;
            }
            odd=l[i];
        }

    }
    cout<<"YES\n";


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
