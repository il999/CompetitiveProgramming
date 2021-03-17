#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve()
{
  int n;
  cin>>n;
  vector <int> l;
  int thing;
  for(int i=0;i<n;i++)
  {
    cin>>thing;
    l.push_back(thing);
  }
  vector <int> l1;
  sort(l.begin(),l.end());
  int check=-1;
  int count=0;
  for(int i=0;i<n;i++)
  {
    if(l[i]!=check)
    {
      cout<<l[i]<<" ";
      check=l[i];
    }else
    {

      l1.push_back(l[i]);
      count++;
    }
  }

  for(int i=0;i<count;i++)
  {
    cout<<l1[i]<<" ";
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
