#include <iostream>

using namespace std;
void solve()
{
  int n,k1,k2;
  int w,b;
  cin>>n;
  cin>>k1;
  cin>>k2;
  cin>>w;
  cin>>b;
  int white=k1+k2;
  int black=2*n-(white);
  if(white/2>=w&&black/2>=b)
  {
    cout<<"YES"<<endl;
  }
  else
  {
    cout<<"NO"<<endl;
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
