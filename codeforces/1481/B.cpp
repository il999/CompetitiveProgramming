#include <iostream>

using namespace std;
void solve()
{
  int n,k;
  cin>>n;
  cin>>k;
  int h[n];
  for(int i=0;i<n;i++)
  {
    cin>>h[i];
  }
  int ind=1;
  for(int i=0;i<k;i++)
  {
    ind=1;
    for(int j=0;j<n;j++)
    {
      if(j==n-1)
      {
        
        cout<<-1<<endl;
        return;
      }
      if(h[j]<h[j+1])
      {
        h[j]+=1;
        j=n+1;
      }else
      {
        ind++;
      }
    }
  }
  cout<<ind<<endl;
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
