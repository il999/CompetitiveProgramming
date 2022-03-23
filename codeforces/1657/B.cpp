// Example program
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,b,x,y;
    cin>>n>>b>>x>>y;
    long long ans=0;
    long long total=0;
    for(int i=0;i<n;i++)
    {
        if(ans+x<=b)
        {
            ans+=x;
            
        }else
        
        {
            ans-=y;   
        }
        total+=ans;
    }
    cout<<total<<"\n";
    
}
    
int main()
{
  int t;
  cin>>t;
  while(t--)
    solve();
}
