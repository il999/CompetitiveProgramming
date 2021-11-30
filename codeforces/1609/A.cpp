#include <iostream>
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
  int temp=0;
  long long realans=0;
  for(int i=0;i<n;i++)
  {
    long long ans=l[i];
    long long tremp=0;
    for(int j=0;j<n;j++)
    {
      temp=l[j];
      if(i!=j)
      {
        while(temp>0&&temp%2==0)
        {
          ans*=2;
          temp/=2;

        }
        tremp+=temp;
      }
      
      
    }
    realans=max(realans,ans+tremp);
  }
  cout<<realans<<endl;
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