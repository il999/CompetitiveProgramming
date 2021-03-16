#include <iostream>

using namespace std;
void solve()
{
  int a,b;
  cin>>a;
  cin>>b;
  if(a==1)
  {
    cout<<0<<" "<<b<<endl;
  }else
  {
    cout<<a-1<<" "<<b<<endl;
  }
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
