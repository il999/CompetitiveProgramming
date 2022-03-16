#include <bits/stdc++.h>
using namespace std;
void solve()
{
 int l,r,a;
 cin>>l>>r>>a;
 if(r%a!=a-1)
 {
     if(l>r-(r%a)-1)
     {
        cout<<r/a+(r%a)<<"\n";   
     }else
     
     {
         cout<<(r-(r%a)-1)/a+a-1<<"\n";
     }
 }else
 
 {
    cout<<r/a+(r%a)<<"\n";   
 }
}
int main() {
  int t;
  cin>>t;
  while(t--)
    solve();
}