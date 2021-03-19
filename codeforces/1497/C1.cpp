#include <iostream>

using namespace std;
void solve()
{
  int n,k;
  cin>>n;
  cin>>k;
  for(int i=0;i<k-3;i++)
  {
    n--;
    k--;
  }
  if(n%2==1)
  {
    cout<<1<<" "<<n/2<<" "<<n/2<<endl;
  }else if(n%2==0 && n%4>0)
  {
    cout<<2<<" "<<(n-2)/2<<" "<<(n-2)/2<<endl;
  }else
  {
    cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
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
