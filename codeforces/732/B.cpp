// Example program
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int l[n];
    for(int i=0;i<n;i++)
        cin>>l[i];
    int additional=0;
    for(int i=0;i<n-1;i++)
    {
        if(l[i]+l[i+1]<k)
        {
            additional+=k-(l[i]+l[i+1]);
            l[i+1]+=k-(l[i]+l[i+1]); 
        }
    }
    cout<<additional<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<l[i]<<" ";   
    }
    cout<<"\n";
}
