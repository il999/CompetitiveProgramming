#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    n/=2;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }

    sort(l,l+n);
    int place=1;
    int c1=0;
    for(int i=0;i<n;i++)
    {
        c1+=abs(l[i]-place);
        //cout<<l[i]<<" "<<place;
        place+=2;
    }
    place=2;
     int c2=0;
    for(int i=0;i<n;i++)
    {
        c2+=abs(l[i]-place);
        place+=2;
    }
    cout<<min(c1,c2)<<"\n";
}
