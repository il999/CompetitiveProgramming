#include <iostream>

using namespace std;
void solve()
{
  int n;
  cin >>n;
  int l[n];

  for(int i=0;i<n;i++)
  {
    cin>>l[i];
  }
  for(int i=0;i<n;i++)
  {
    if(l[i]%2==1)
    {
      cout<<l[i]<<" ";
    }
  }
  for(int i=0;i<n;i++)
  {
    if(l[i]%2==0)
    {
      cout<<l[i]<<" ";
    }
  }
  cout<<endl;
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
