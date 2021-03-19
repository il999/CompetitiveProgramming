#include <iostream>

using namespace std;

int main()
{

   long long n,m;
    cin>>n;
    cin>>m;

    long long count1=0;

    for(int i=1;i<=n;i++)
    {
      count1+=(m+i%5)/5;

    }


    cout<<count1<<endl;
}
