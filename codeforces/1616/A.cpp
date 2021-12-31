 #include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        l[i]=abs(l[i]);
    }
    sort(l,l+n);
    int c=0;
    int last=10000;
    int t=0;
    for(int i=0;i<n;i++)
    {
        if(l[i]!=last)
        {

                c=1;
                t++;
                last=l[i];
        }
        else{
            if(c<2&&l[i]!=0)
            {
                c++;
                t++;
            }
        }
    }
    cout<<t<<endl;

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
