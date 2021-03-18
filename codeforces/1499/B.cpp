#include <iostream>

using namespace std;
void solve()
{
  string s;
  cin>>s;
  bool check=true;

  int count1=0;
  int count2=0;
  int count12=0;
  int count22=0;
  bool morethan2=false;
  bool morethan1=false;
  bool check2=true;

  for(int i=0;i<s.size();i++)
  {
    if(count2==2&&count12>0&&morethan2)
    {

      morethan1=true;
    }
    if(count1==2)
    {

      morethan2=true;
    }

    if(s[i]=='1')
    {
      count2=0;
      count1++;
      check=false;
      count12++;
    }else
    {
      check2=false;
      count1=0;
      count22++;
      count2++;
    }
  }
  if(count2==2&&count12>0)
  {

    morethan1=true;
  }
  if(count1==2)
  {

    morethan2=true;
  }

  if(morethan1==true&&morethan2==true&&(check==false&&check2==false))
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
