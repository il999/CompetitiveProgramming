#include <iostream>

using namespace std;
void solve()
{
  int n;
  cin>>n;
  int cream[n];
  int result[n];
  for(int i=0;i<n;i++)
  {
    cin>>cream[i];
    result[i]=0;
  }
  int creamn=0;
  for(int i=n-1;i>=0;i--)
  {
    if(creamn>0)
    {
      if(cream[i]>creamn)
      {
        creamn=cream[i];
      }
      result[i]=1;
      creamn--;
    }else
    {
      creamn+=cream[i];
      if(creamn>0)
      {
        result[i]=1;
        creamn--;
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    cout<<result[i]<<" ";
}
  cout<<endl;
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
