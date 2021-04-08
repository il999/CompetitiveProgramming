#include <iostream>

using namespace std;
void printing(int m, string n)
{
  cout<<"YES"<<endl;
  for(int i=0;i<m;i++)
  {
    cout<<n[i];
  }
  cout<<'a';
  for(int i=m;i<n.length();i++)
  {
    cout<<n[i];
  }
  cout<<endl;
}
void solve()
{
  string n;
  cin>>n;
  int len=n.length()-1;
  for(int i=0;i<=len;i++)
  {
    if(n[len-i]!='a')
    {
      
      printing(i,n);
      return;
    }
  }
  cout<<"NO"<<endl;
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
