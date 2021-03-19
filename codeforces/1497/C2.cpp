#include <iostream>

using namespace std;
void solve()
{
  int n,k;
  cin>>n;
  cin>>k;
  int l=0;
  if(k>3)
  {

  l=k-3;
  n-=k-3;
  k=k-3;

}
  if(n%2==1)
  {
    cout<<1<<" "<<n/2<<" "<<n/2<<" ";
  }else if(n%2==0 && n%4>0)
  {
    cout<<2<<" "<<(n-2)/2<<" "<<(n-2)/2<<" ";
  }else
  {
    cout<<n/2<<" "<<n/4<<" "<<n/4<<" ";
  }
  for(int i=0;i<l;i++)
  {
    cout<<1<<" ";
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
