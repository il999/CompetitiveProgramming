#include <iostream>

using namespace std;
void solve()

{
  int n;
  cin>>n;
  string s;
  cin>>s;
  int m=0;
  int t=0;
  int mtemp=0;
  bool tee=false;
  int em=false;

  for(int i=0;i<n;i++)
  {
    if(s[i]=='T')
    {
      t++;
      tee=true;
      if(em>0)
      {
        m++;
        em--;
      }
    }else if (tee)
    {
      em++;
      if(em+m>t)
      {
        cout<<"NO"<<endl;
        return;
      }
    }else
    {
      cout<<"NO"<<endl;
      return;
    }
  }
  if(em>0)
  {
    cout<<"NO"<<endl;
    return;
  }
  if(t!=m*2)
  {
    cout<<"NO"<<endl;
  }else
  {
    cout<<"YES"<<endl;
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
