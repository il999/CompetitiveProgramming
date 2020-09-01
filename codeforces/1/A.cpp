#include <iostream>

using namespace std;

int main()
{
    long long int n=0;
    long long int m=0;
    int a=0;
    long long int l=0;
    long long int k=0;
    cin>>n;
    cin>>m;
    cin>>a;
    long long int sum=n*m;
    if(n%a==0)
    {
        l=n/a;
    }else{
        l=(n/a)+1;
    }
    if(m%a==0)
    {
        k=m/a;
    }else{
        k=(m/a)+1;
    }

    cout<<l*k;








}
