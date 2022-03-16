#include <bits/stdc++.h>
using namespace std;
void solve()
{
  string s;
  string n;
  cin>>s;
  cin>>n;
  for(int i=0;i<s.size();i+=2)
  {
    if(s[i]==n[0])
    {
        
     cout<<"YES"<<"\n";
     return;
        
    }
  }
  cout<<"NO"<<"\n";
}
int main() {
  int t;
  cin>>t;
  while(t--)
    solve();
}