// Example program
#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long n;
  cin>>n;
  vector<int> v;
  long long no=1;
  while(n>0)
  {
      v.push_back(n%10);
      n/=10;
      no*=9;
  }
  
  long long pre[v.size()+1];
  pre[0]=0;
  pre[1]=v[0];
  long long nine[v.size()];
  nine[0]=1;
  
  for(int i=1;i<v.size();i++)
  {
      pre[i+1]=pre[i]*v[i];
      nine[i]=nine[i-1]*9;
  }
  
  
  long long c=1;
  long long t=1;
  long long ans=v[0];
  long long one=1;
  for(int i=v.size()-1;i>0;i--)
  {
      c=max(t*(v[i]-1),one);
      t*=v[i];
        //cout<<t<<"\n";
       // cout<<ans<<"\n";
      ans=max(t*(pre[i]),ans);
      ans=max(ans,c*nine[i]);
      
  }
  cout<<ans<<"\n";
  
}