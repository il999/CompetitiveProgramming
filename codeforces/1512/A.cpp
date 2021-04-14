#include <iostream>

using namespace std;
void solve()
{
  int n;
  cin>>n;
  int l[n];
  for(int i=0;i<n;i++)
  {
    cin>>l[i];
  }
  if(l[0]!=l[1])
  {
    if(l[1]==l[2])
    {
      cout<<1<<endl;
      return;
    }
  }
  for(int i=1;i<n-1;i++)
  {
    if(l[i]!=l[i-1]&&l[i]!=l[i+1])
    {
      cout<<i+1<<endl;
      return;
    }
  }
  cout<<n<<endl;;

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
