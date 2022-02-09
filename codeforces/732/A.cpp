// Example program
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,r;
    cin>>k>>r;
    int thing=k%10;
    int m=100;
    for(int i=1;i<11;i++)
    {
        if((i*k)%10==r)
        {
            m=i;
            break;
        }else if((i*k)%10==0)
        {
            m=i;
            break;
        }
    }
    cout<<m<<endl;
}
