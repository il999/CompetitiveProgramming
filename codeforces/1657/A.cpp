// Example program
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x,y;
    cin>>x>>y;
    if(x==0&&y==0)
    {
        cout<<0<<"\n";   
        return;
    }
    double result=sqrt(x*x+y*y);
    double one=1;
    if(result==int(result))
    {
        cout<<1<<"\n";
    }else
    
    {
        cout<<2<<"\n";   
    }
}
    
int main()
{
  int t;
  cin>>t;
  while(t--)
    solve();
}
