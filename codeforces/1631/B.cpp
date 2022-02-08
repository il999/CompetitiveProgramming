// Example program
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int l[n];
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    int needed=l[n-1];
    long long ans=0;
    int distance=1;
    for(int i= n-2;i>=0;i--)
    {
        if(l[i]==needed&&n-i>distance)
        {
            distance++;
        }else if(l[i]!=needed&&n-i>distance)
        {
            ans++;
            distance*=2;
        }
    }
    cout<<ans<<"\n";
    
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