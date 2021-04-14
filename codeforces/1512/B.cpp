#include <iostream>

using namespace std;
void solve()
{
  int n;
  cin>>n;
  string s[n];
  for(int i=0;i<n;i++)
  {
    cin>>s[i];

  }
  int a=-1;
  int b=0;
  int a1;
  int b1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(s[i][j]=='*')
      {
        if(a==-1)
        {
          a=i;
          a1=j;
        }else
        {
          b=i;
          b1=j;
        }

      }
    }
  }
  if(a==b)
  {
    if(a+1<n)
    {
      s[a+1][a1]='*';
      s[a+1][b1]='*';
    }else
    {
      s[a-1][a1]='*';
      s[a-1][b1]='*';
    }
    for(int i=0;i<n;i++)
    {

        cout<<s[i]<<endl;

    }
    return;
  }
  if(a1==b1)
  {
    if(a1+1<n)
    {
      s[a][a1+1]='*';
      s[b][b1+1]='*';
    }else
    {
      s[a][a1-1]='*';
      s[b][b1-1]='*';
    }
    for(int i=0;i<n;i++)
    {

        cout<<s[i]<<endl;

    }
    return;
  }
  s[a][b1]='*';
  s[b][a1]='*';
  for(int i=0;i<n;i++)
  {

      cout<<s[i]<<endl;

  }
  return;
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
