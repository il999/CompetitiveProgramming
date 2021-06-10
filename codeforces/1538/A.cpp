#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve()
{
  int n;
  cin>>n;
  int max1,min1;
  max1=0;
  min1=0;
  int max2=0;
  int min2=1000000;
  int l[n];
  for(int i=0;i<n;i++)
  {
    cin>>l[i];
    if(l[i]>max2)
    {
      max1=i+1;
      max2=l[i];
    }
    if(l[i]<min2)
    {
      min1=i+1;
      min2=l[i];
    }
  }
  
  int next=min(max(max1,min1),min(min1,max1)+n-max(max1,min1)+1);
  int new1=min(next,n-min(max1,min1)+1);
  cout<<new1<<endl;
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
