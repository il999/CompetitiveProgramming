#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
  long long a,b;
  cin>>a>>b;
  long long q=a-1;
  if(((a*(a+1))/2)+((q*(q+1))/2)<b)
  {
    cout<<(a*2)-1<<endl;
  }else if((a*(a+1))/2<b)
  {
    b-=(a*(a+1))/2;
    long long q=a-1;
    long long low=0;
    long long high=q;
    long long mid=(low+high)/2;
    long long ans=(q*(q+1))/2;
    while(low<high)
    {
      mid=(low+high)/2;
      if(ans-((mid*(mid+1))/2)<b)
      {
        high=mid;
      }else
      {
        low=mid+1;
      }
    }
    if(ans-((mid*(mid+1))/2)<b)
    {
      mid--;
    }
    cout<<(a-mid-1)+a<<endl;

  }else
  {
    long long low=0;
    long long high=a;
    long long mid=(low+high)/2;
    while(low<high)
    {
      mid=(low+high)/2;
      if((mid*(mid+1))/2<b)
      {
        low=mid+1;
      }else
      {
        high=mid;
      }
    }
    if((mid*(mid+1))/2<b)
    {
      mid++;
    }
    cout<<mid<<endl;
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
