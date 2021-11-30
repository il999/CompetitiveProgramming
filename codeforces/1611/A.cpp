#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
  long long n;
  cin>>n;
  vector<int> v;
  bool val=false;
  while(n>0)
  {
    v.push_back(n%10);
    if((n%10)%2==0)
    {
      val=true;
    }
    n/=10;
  }
  if(!val)
  {
    cout<<-1<<endl;
  }else if(v[0]%2==0)
  {
    cout<<0<<endl;
  }else if(v[v.size()-1]%2==0)
  {
    cout<<1<<endl;
  }else 
  {
    cout<<2<<endl;
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