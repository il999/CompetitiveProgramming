#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n,h;
    cin>>n>>h;
    long long l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    long long low=0;
    long long mid=0;
    long long high=h;
    long long total=0;
    long long last=l[0];
    while(low<high)
    {
        total=0;
        mid=(low+high)/2;

        for(int i=1;i<n;i++)
        {
            total+=min(l[i]-l[i-1],mid);



        }
        total+=mid;

        if(total<h)
        {
            low=mid+1;
        }else
        {
            high=mid;
        }

    }
    cout<<high<<endl;

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
