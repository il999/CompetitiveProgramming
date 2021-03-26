#include <iostream>

using namespace std;
void solve()
{
  long long n,m,x;
  cin>>n;
  cin>>m;
  cin>>x;
  x--;
  long long ans=0;
  long long r=x%n;
  long long c=x/n;
  cout<<r*m+c+1<<endl;



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
