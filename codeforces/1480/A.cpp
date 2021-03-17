#include <iostream>

using namespace std;
void solve()
{
  string a;
  cin>>a;
  string b="";
  int turn=0;
  int num;
  for(int i=0;i<a.size();i++)
  {
    num=a[i];
    if(turn==0)
    {
      turn++;
      if(num!='a')
      {
        b+='a';
      }else
      {
        b+=(a[i]+=1);
      }
    }else
    {
      turn=0;
      if(a[i]!='z')
      {
        b+='z';
      }else
      {
        b+=(a[i]-=1);
      }
    }
  }
  cout<<b<<endl;
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
