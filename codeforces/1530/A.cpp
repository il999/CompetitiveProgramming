#include <iostream>

using namespace std;
void solve()
{
  int n;
  cin>>n;
  int max1=1;
  while(n>1)
  {
    if(n%10>max1)
    {
      max1=n%10;
    }
    n/=10;
  }
  cout<<max1<<endl;
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
