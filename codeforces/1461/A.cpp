#include <iostream>

using namespace std;
void solve()
{
  int n,k;
  cin>>n;
  cin>>k;
  string s;

  char added='a';
  int num=0;
  int changed=0;
  int j;
  if(k==1)
  {
      j=k;
  }
  else
  {
    j=1;
  }
  for(int i=0;i<n;i++)
  {
    if(num<j)
    {
      num++;
      s+=added;
    }else
    {
      num=1;
      changed++;
      if(changed==2)
      {
        added='c';

      }else if(changed==3)
      {
        changed=0;
        added='a';

      }else
      {

      added='b';

    }

    s+=added;

    }
  }
  cout<<s<<endl;
}
int main()
{

      int t;
      cin>>t;
      while(t--)
      {
        solve();
      }
      return 0;
}
